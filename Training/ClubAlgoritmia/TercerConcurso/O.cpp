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

unordered_map<int,unordered_set<int>> jumps;
unordered_map<int,unordered_set<int>> longjump;
vector<int> minimos;
vector<bool> visited;
queue<int> nexts;
int getJumps(int &k){
    int contlevel=0;
    int level=0;
    int current=0;

    while(!nexts.empty()){
        int s=nexts.front();
        nexts.pop();
        contlevel--;
        for(auto &x:jumps[s]){
            if(!visited[x]){
                visited[x]=true;
                nexts.push(x);
                level++;
            }
            if(minimos[s]+1<minimos[x]){
                minimos[x]=minimos[s]+1;
            }
        }
        for(auto &x:longjump[s%k]){
            if(x!=s){
                if(!visited[x]){
                    nexts.push(x);
                    visited[x]=true;
                    level++;
                }
                if(minimos[s]+1<minimos[x]){
                    minimos[x]=minimos[s]+1;
                }
            }
        }
        if(contlevel==0){
            current++;
            contlevel=level;
            level=0;

        }
    }
    return 1e9;
}


int main()
{
    IO;
    int n,m,k,u,v,s,t;
    cin>>n>>m>>k;
    minimos=vector<int>(n+1,1e9);
    visited=vector<bool>(n+1,false);
    FOR(i,1,m+1){
        cin>>u>>v;
        jumps[u].insert(v);
        longjump[u%k].insert(u);
        longjump[v%k].insert(v);
    }
    cin>>s>>t;
    minimos[s]=0;
    nexts.push(s);
    visited[s]=true;
    getJumps(k);
    if(minimos[t]==1e9){
        cout<<-1<<ENDL;
    }else{
        cout<<minimos[t]<<ENDL;
    }
    return 0;
}