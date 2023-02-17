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

lli getPath(vector<vector<pair<int,int>>>&g,int s, int d){
    vector<lli> dist(g.size(),LLONG_MAX);
    vector<bool> visited(g.size(),false);
    dist[s]=0;
    priority_queue<pair<lli,int>> nex;
    nex.push({0,s});
    while(nex.size()){
        auto current=nex.top();
        nex.pop();
        if(!visited[current.second]){
            visited[current.second]=true;
            for(auto x:g[current.second]){
                if(dist[current.second]+x.second<dist[x.first]){
                    dist[x.first]=dist[current.second]+x.second;
                    nex.push({dist[x.first],x.first});
                }
            }
        }
    }
    return dist[d];
}

int main()
{
    IO;
    int t,cont=1,n,m,s,d,a,b,c;
    cin>>t;

    while(t--){
        cin>>n>>m>>s>>d;
        vector<vector<pair<int,int>>> g(n);
        FOR(i,0,m){
            cin>>a>>b>>c;
            g[a].push_back({b,c});
            g[b].pb({a,c});
        }
        lli res=getPath(g,s,d);
        if(res<LLONG_MAX){
            cout<<"Case #"<<cont++<<": "<<res<<ENDL;
        }else{
            cout<<"Case #"<<cont++<<": unreachable"<<ENDL;
        }
    }
    return 0;
}