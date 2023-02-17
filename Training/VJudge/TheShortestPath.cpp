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

lli getPath(vector<vector<pair<int,int>>> &g,string a, string b, unordered_map<string,int> &aux){
    vector<lli> dist(g.size()+1,LLONG_MAX);
    dist[aux[a]]=0;
    vector<bool> visited(g.size()+1,false);
    priority_queue<pair<lli,int>, vector<pair<lli,int>>, greater<pair<lli,int>>> nex;
    nex.push({0,aux[a]});
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
    return dist[aux[b]];
}

int main()
{
    IO;
    int t,n,x,y,c,q;
    cin>>t;
    string s,a,b;
    while(t--){
        cin>>n;
        unordered_map<string,int> aux;
        vector<vector<pair<int,int>>> g(n+1);
        FOR(i,1,n+1){
            cin>>s;
            cin>>x;
            aux[s]=i;
            FOR(j,0,x){
                cin>>y>>c;
                g[i].push_back({y,c});
            }
        }

        cin>>q;
        while(q--){
            cin>>a>>b;
            cout<<getPath(g,a,b,aux)<<ENDL;
        }


    }
    return 0;
}