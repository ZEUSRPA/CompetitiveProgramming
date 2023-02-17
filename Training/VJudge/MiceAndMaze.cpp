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

int getMice(vector<vector<pair<int,int>>> &g,int p,int t){
    vector<bool> visited(g.size(),false);
    queue<pair<int,int>> nex;
    nex.push({p,t});
    visited[p]=true;
    int cont=0;
    while(nex.size()){
        auto current=nex.front();
        nex.pop();
        if(current.first!=p)
            cont++;
        for(auto x:g[current.first]){
            if(!visited[x.first]&&x.second<=current.second){
                visited[x.first]=true;
                nex.push({x.first,current.second-x.second});
            }
        }
    }
    return cont;
}

int main()
{
    IO;
    int n,e,t,m,a,b,c;
    cin>>n>>e>>t>>m;
    vector<vector<pair<int,int>>> g(n);

    FOR(i,0,m){
        cin>>a>>b>>c;
        a--;
        b--;
        g[b].pb({a,c});
    }

    cout<<getMice(g,--e,t)<<ENDL;
    return 0;
}