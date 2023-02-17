// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define F first
#define S second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define ALL(s) begin(s), end(s)
#define ALLR(s) rbegin(s), rend(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;


vector<bool> visited;

int getAns(vector<vector<int>> &g,int a){
    lli ans = 1;
    for(auto x: g[a]){
        if(!visited[x]){
            visited[x]=true;
            ans+=getAns(g,x);
        }
    }
    return ans;
}

int main() {_ 
    int t,n,m,l,a,b;
    cin>>t;
    while(t--){
        cin>>n>>m>>l;
        vector<vector<int>> g(n+1);
        visited=vector<bool>(n+1,false);
        fore(i,0,m){
            cin>>a>>b;
            g[a].pb(b);
        }
        int ans = 0;
        fore(i,0,l){
            cin>>a;
            if(!visited[a]){
                visited[a]=true;
                ans+=getAns(g,a);
            }
        }
        cout<<ans<<ENDL;
    }
    return 0;
}