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

int main(){
    IO;
    int n,k,a,b;
    cin>>n>>k;
    priority_queue<int,vector<int>,greater<int>> nex;
    vector<vector<int>> tree(n+1,vector<int>());
    for(int i=0;i<n-1;++i){
        cin>>a>>b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    vector<int> ans;
    vector<int> used(n+1,false);
    nex.push(1);
    used[1]=true;
    while(nex.size()){
        int current=nex.top();
        nex.pop();
        ans.pb(current);
        int lvl=0;
        queue<int> cola;
        cola.push(current);
        unordered_map<int,int> visited;
        visited[current]=1;
        while(cola.size()){
            int c=cola.size();
            while(c--){
                int currentcola=cola.front();
                cola.pop();
                for(auto x:tree[currentcola]){
                    if(visited[x]==0){
                        visited[x]=1;
                        if(!used[x]){
                            nex.push(x);
                            used[x]=true;
                        }
                        cola.push(x);
                    }
                }
            }
            lvl++;
            if(lvl==k){
                break;
            }
        }
    }
    for(int i=0;i<ans.size()-1;++i){
        cout<<ans[i]<<" ";
    }
    cout<<ans[ans.size()-1]<<ENDL;
    return 0;
}