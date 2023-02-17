#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define mp make_pair
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


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,a,b,c,s,e;
    cin>>t;
    while(t--){
        unordered_map<int,int> snakes;
        cin>>a>>b>>c;
        vector<int> players(a,1);
        FOR(i,0,b){
            cin>>s>>e;
            snakes[s]=e;
        }
        int p=0;
        bool end=false;
        FOR(i,0,c){
            cin>>s;
            if(!end){
                if(snakes.count(players[p]+s)){
                    players[p]=snakes[players[p]+s];
                    if(players[p]==100){
                        end=true;
                    }
                }else{
                    players[p]+=s;
                    if(players[p]>=100){
                        players[p]=100;
                        end=true;
                    }
                }
            }
            p++;
            p%=a;

        }
        FOR(i,0,a){
            cout<<"Position of player "<<i+1<<" is "<<players[i]<<"."<<ENDL;
        }
    }
    return 0;
}