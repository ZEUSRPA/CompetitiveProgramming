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

bool bicolorable(unordered_map<int,unordered_map<int,int>> &g,vector<int> &color,vector<bool> &visited,int n){
    visited[n]=true;
    for(auto x:g[n]){
        if(color[x.first]==color[n]){
            return false;
        }else{
            color[x.first]=color[n]==1?0:1;
            if(visited[x.first]==false)
                if(!bicolorable(g,color,visited,x.first)){
                    return false;
                }
        }
    }
    return true;
}


int main()
{
    IO;
    int n,l,a,b;
    while(cin>>n){
        if(n==0){
            break;
        }
        cin>>l;
        unordered_map<int,unordered_map<int,int>> graph;
        vector<int> color(n,-1);
        vector<bool> visited(n,false);
        FOR(i,0,l){
            cin>>a>>b;
            graph[a][b]++;
            graph[b][a]++;
        }
        color[0]=1;
        cout<<(bicolorable(graph,color,visited,0)?"BICOLORABLE.":"NOT BICOLORABLE.")<<ENDL;

    }
    return 0;
}