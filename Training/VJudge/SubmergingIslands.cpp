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

vector<bool> visited;
vector<int> tin,low;
int currenttime;

int getArticulations(vector<vector<int>> &g, int node, int p=-1){
    visited[node]=true;
    int articulationpoints=0;
    low[node]=tin[node]=currenttime++;
    int children=0;
    bool isarticulation=false;
    for(int x:g[node]){
        if(x==p)continue;
        if(visited[x]){
            low[node]=min(low[node],tin[x]);
        }else{
            articulationpoints+=getArticulations(g,x,node);
            low[node]=min(low[node],low[x]);
            if(low[x]>=tin[node]&&p!=-1){
                isarticulation=true;
            }
            children++;
        }
    }
    if(p==-1&&children>1){
        isarticulation=true;
    }
    if(isarticulation){
        articulationpoints++;
    }
    return articulationpoints;

}

int main()
{
    IO;
    int n,m,a,b;
    while(cin>>n>>m){
        if(n==0&&m==0){
            break;
        }
        vector<vector<int>> g(n+1);
        visited=vector<bool>(n+1,false);
        tin=low=vector<int>(n+1,-1);
        currenttime=0;
        FOR(i,0,m){
            cin>>a>>b;
            g[a].pb(b);
            g[b].pb(a);
        }
        cout<<getArticulations(g,1)<<ENDL;
    }
    return 0;
}