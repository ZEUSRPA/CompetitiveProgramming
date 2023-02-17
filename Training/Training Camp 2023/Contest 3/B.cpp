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

vector<lli> dists;

void disjktra(vector<vector<pair<lli,lli>>>& adj, lli s){
    dists[s]=0;
    priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>> nex;
    nex.push({0,s});
    while(nex.size()){
        auto current = nex.top();
        nex.pop();
        if(dists[current.second]==current.first){
            dists[current.second]=current.first;
            for(auto x:adj[current.second]){
                if(current.first+x.second<dists[x.first]){
                    dists[x.first]=current.first+x.second;
                    nex.push({dists[x.first],x.first});
                }
            }
        }
    }

}

int main() {_
    lli n,m,u,v,w,k,q,s,d;
    cin>>n>>m;
    vector<vector<pair<lli,lli>>> adj(2*n);
    fore(i,0,m){
        cin>>u>>v>>w;
        adj[u].pb({v,2LL*w});
        adj[v].pb({u,2LL*w});
        adj[n+u].pb({n+v,w});
        adj[n+v].pb({n+u,w});
        adj[n+u].pb({u,0});
        adj[n+v].pb({v,0});
    }
    cin>>k;
    vector<lli> locations(k);
    fore(i,0,k){
        cin>>locations[i];
    }
    cin>>q;
    vector<lli> special(q);
    fore(i,0,q){
        cin>>special[i];
    }
    cin>>s>>d;
    dists = vector<lli>(2*n+3,LLONG_MAX);
    disjktra(adj,d);
    lli thief = dists[s]/2;

    fore(i,0,q){
        adj[special[i]].pb({n+special[i],0});
    }

    disjktra(adj,d);
    lli police = LLONG_MAX;
    fore(i,0,k){
        police = min(dists[locations[i]],police);
    }

    if(police/2<=thief){
        cout<<-1<<ENDL;
    }else{
        cout<<thief<<ENDL;
    }

    return 0;
}