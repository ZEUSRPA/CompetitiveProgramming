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

int main()
{
    IO;
    int n,k,a,b,w;
    cin>>n>>k;
    vector<vector<pair<int,int>>> g(n+1);
    
    FOR(i,1,n){
        cin>>a>>b>>w;
        g[a].pb({w,b});
        g[b].pb({w,a});
    }

    unordered_set<int> res;
    FOR(i,0,k){
        cin>>a;
        res.insert(a);
        sort(g[a].begin(),g[a].end());
        if(g[a].size()==1){
            res.insert(g[a][0].S);
        }else if(g[a][0].F<g[a][1].F){
            res.insert(g[a][0].S);
        }
    }
    cout<<res.size()<<ENDL;
    


    return 0;
}
