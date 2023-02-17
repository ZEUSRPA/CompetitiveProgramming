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

bool verify(vector<vector<int>> &g,vector<int> &gender,int p){
    for(auto x:g[p]){
        if(gender[p]==gender[x]){
            return false;
        }else{
            if(gender[x]==-1){
                gender[x]=(gender[p]==1)?0:1;
                if(!verify(g,gender,x)){
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    IO;
    int t,n,m,a,b;
    cin>>t;
    int s=0;
    while(s++<t){
        cin>>n>>m;
        vector<vector<int>> g(n);
        FOR(i,0,m){
            cin>>a>>b;
            a--;
            b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        vector<int> gender(n,-1);
        bool si=true;
        FOR(i,0,n){
            if(gender[i]==-1){
                gender[i]=1;
                si&=verify(g,gender,i);
            }
        }
        cout<<"Scenario #"<<s<<":"<<ENDL;
        cout<<(si?"No suspicious bugs found!":"Suspicious bugs found!")<<ENDL;
        
    }
    return 0;
}