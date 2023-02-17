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


//Lista de adyacencia

//Hackerearth

vector<bool> visited;

bool res(int a, int b,vector<vector<int>> &graph){
    ///BFS;
    //DFS;
    visited[a]=true;
    for(auto x:graph[a]){
        if(x==b){
            return true;
        }
    }
    for(auto x:graph[a]){
        if(visited[x]==false){
            
            if(res(x,b,graph)){
                return true;
            }
        }
        
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,c,a,b;
    cin>>n>>c;
    vector<vector<int>> graph(n+1);
    
    for(int i=0;i<c;++i){
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;++i){
        visited=vector<bool>(n+1,false);
        cin>>a>>b;
        cout<<(res(a,b,graph)?"Yes":"No")<<ENDL;
    }

    return 0;
}

