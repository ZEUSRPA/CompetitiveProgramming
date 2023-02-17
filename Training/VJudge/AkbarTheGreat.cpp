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

void bfs(unordered_map<int,unordered_map<int,int>> &g,vector<int> &guards,int node,int n,int power){
    vector<bool> visited(n+1,false);
    queue<int> nex;
    nex.push(node);
    visited[node]=true;
    int lvl=0;
    while(nex.size()&&lvl<=power){
        int c=nex.size();
        while(c--){
            int current=nex.front();
            guards[current]++;
            nex.pop();
            for(auto x:g[current]){
                if(!visited[x.first]){
                    visited[x.first]=true;
                    nex.push(x.first);
                }
            }
        }
        lvl++;
    }
}

int main()
{
    IO;
    int t,r,n,m,a,b;
    cin>>t;
    while(t--){
        cin>>n>>r>>m;
        unordered_map<int,unordered_map<int,int>> g;
        FOR(i,0,r){
            cin>>a>>b;
            g[a][b]++;
            g[b][a]++;
        }

        vector<int> guards(n+1,0);
        FOR(i,0,m){
            cin>>a>>b;
            bfs(g,guards,a,n,b);

        }
        bool si=true;
        FOR(i,1,n+1){
            if(guards[i]!=1){
                si=false;
                break;
            }
        }
        cout<<(si?"Yes":"No")<<ENDL;
    }
    return 0;
}