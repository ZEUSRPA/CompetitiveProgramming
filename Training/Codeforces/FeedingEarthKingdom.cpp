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
vector<bool> visited;

int dfs(vector<vector<int>> &graph,int p){
    if(visited[p]){
        return false;
    }
    visited[p]=true;
    for(auto x:graph[p]){
        if(!visited[x]){
            dfs(graph,x);
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    visited=vector<bool> (n+1,false);
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;++i){
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int res=0;
    for(int i=1;i<=n;++i){
        if(dfs(graph,i)){
            res++;
        }
    }
    cout<<res<<ENDL;
    return 0;
}

