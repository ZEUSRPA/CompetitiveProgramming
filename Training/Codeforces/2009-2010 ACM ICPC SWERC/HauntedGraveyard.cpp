#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ld long double
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;

vector<vector<lli>> dp;
vector<vector<int>> dpd;
vector<vector<int>> graveyard;
vector<pair<int,pair<int,int>>> holes;
lli currenttime;
lli inhole;
bool never;

lli getAns(pair<int,int> pos){
    if(pos.first==graveyard.size()-1&&pos.second==graveyard[0].size()-1){
        return 0;
    }
    if(dpd[pos.first][pos.second]==1){
        return dp[pos.first][pos.second];
    }
    if(dpd[pos.first][pos.second]==0){
        return LLONG_MAX;
    }
    lli current=LLONG_MAX;

    if(graveyard[pos.first][pos.second]>=0){
        dpd[pos.first][pos.second]=0;
        inhole++;
        if(inhole==1){
            currenttime=0;
        }
        currenttime+=holes[graveyard[pos.first][pos.second]].second.second;
        current=min(current,getAns({holes[graveyard[pos.first][pos.second]].first,holes[graveyard[pos.first][pos.second]].second.first}));
        if(current!=LLONG_MAX){
            dp[pos.first][pos.second]=current+holes[graveyard[pos.first][pos.second]].second.second;
        }else{
            dp[pos.first][pos.second]=current;
            if(inhole==1){
                if(currenttime<0){
                    never=true;
                }
            } 
        }
        inhole--;
        dpd[pos.first][pos.second]=1;
    }else{
        vector<pair<int,int>> steps={{-1,0},{1,0},{0,1}};
        dpd[pos.first][pos.second]=0;
        for(auto x:steps){
            int a=pos.first+x.first;
            int b=pos.second+x.second;
            if(a<graveyard.size()&&a>=0&&b>=0&&b<graveyard[0].size()&&graveyard[a][b]!=-2){
                current=min(current,getAns({a,b}));
            }
        }
        if(current!=LLONG_MAX){
            dp[pos.first][pos.second]=current+1;
        }else{
            dp[pos.first][pos.second]=current;
        }
        dpd[pos.first][pos.second]=1;
    }

    
    return dp[pos.first][pos.second];
}

int main()
{
    IO;
    int w,h,g,x,y,xx,yy,t,e;
    while(cin>>w>>h){

        if(w==0&& h==0)break;
        graveyard=vector<vector<int>> (w,vector<int>(h,-1));
        dpd=vector<vector<int>>(w,vector<int>(h,-1));
        dp=vector<vector<lli>>(w,vector<lli>(h,LLONG_MAX));
        cin>>g;
        currenttime=0;
        never=false;
        FOR(i,0,g){
            cin>>x>>y;
            graveyard[x][y]=-2;
        }
        cin>>e;
        inhole=0;
        holes.clear();
        FOR(i,0,e){
            cin>>x>>y>>xx>>yy>>t;
            graveyard[x][y]=holes.size();
            holes.pb({xx,{yy,t}});
        }

        lli res=getAns({0,0});
        if(never){
            cout<<"Never"<<ENDL;
        }else{
            if(dp[w-1][h-1]==LLONG_MAX){
                cout<<"Impossible"<<ENDL;
            }else{
                cout<<dp[w-1][h-1]<<ENDL;
            }
        }
    }
    return 0;
}