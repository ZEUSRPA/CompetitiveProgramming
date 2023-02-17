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
#define vvi vector<vector<int>>
#define vi vector<int>
#define vvl vector<vector<lli>>
#define vl vector<lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;

vector<vector<pii>> dp;

pii getAns(vvi &grid, pii pos,int cont){
    if(dp[pos.first][pos.second].first!=-1){
        return dp[pos.first][pos.second];
    }
    int res=0;
    vector<pii> steps={{0,-1},{-1,0},{0,1},{1,0}};
    for(auto x:steps){
        int a=pos.first+x.first;
        int b=pos.second+x.second;
        if(a>=0&&a<grid.size()&&b>=0&&b<grid[0].size()&&grid[a][b]-grid[pos.first][pos.second]==1){
            auto answer=getAns(grid,{a,b},cont+1);
            if(answer.second+cont>3){
                res+=answer.first;
            }
        }
    }
    if(res==0){
        if(cont>3){
            dp[pos.first][pos.second]={1,cont};
        
        }else{
            dp[pos.first][pos.second]={0,cont};
        }
    }else{
        dp[pos.first][pos.second]={res,cont};
    }
    return dp[pos.first][pos.second];

}

int main()
{
    IO;
    int n,m;
    cin>>n>>m;
    vvi grid(n,vi(m));
    dp=vector<vector<pii>>(n,vector<pii>(m,{-1,0}));
    vector<pair<int,pii>> minis(n*m);
    int pos=0;
    FOR(i,0,n){
        FOR(j,0,m){
            cin>>grid[i][j];
            minis[pos].first=grid[i][j];
            minis[pos].second={i,j};
            pos++;
        }
    }
    sort(ALL(minis));
    int res=0;
    FOR(i,0,minis.size()){
        if(dp[minis[i].second.first][minis[i].second.second].first==-1){
            res+=getAns(grid,minis[i].second,1).first;
        }
    }
    cout<<res<<ENDL;
    return 0;
} 