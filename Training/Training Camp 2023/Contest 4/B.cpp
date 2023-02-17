// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define F first
#define S second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;


vector<lli> getAns(vector<vector<pair<lli,lli>>> &adj,lli s){
    vector<lli> ans(adj.size(),LLONG_MAX);
    priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>> nex;
    nex.push({0,s});
    ans[s]=0;
    while(nex.size()){
        auto current = nex.top();
        nex.pop();
        if(ans[current.second]==current.first){
            for(auto x:adj[current.second]){
                if(current.first+x.second<ans[x.first]){
                    ans[x.first] = current.first+x.second;
                    nex.push({ans[x.first],x.first});
                }
            }
        }
    }
    return ans;

}

int main() {_
    lli n,m,u,v,w;
    cin>>n>>m;
    vector<vector<pair<lli,lli>>> adj(2*n+1);
    fore(i,0,m){
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u+n,w});
        adj[v+n].pb({u+n,w});
    }
    auto ans = getAns(adj,1);
    fore(i,2,n+1){
        ans[i]=min(ans[i],ans[i+n]);
        cout<<(ans[i]!=LLONG_MAX?ans[i]:-1)<<" ";
    }
    cout<<ENDL;
    return 0;
}