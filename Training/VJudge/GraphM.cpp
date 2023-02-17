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
#define SZ(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

bool getAns(vector<vector<int>>& g){
    vector<int> color(g.size(),-1);
    queue<int>nex;
    color[0]=0;
    nex.push(0);
    while(nex.size()){
        lli c=nex.size();
        while(c--){
            int current=nex.front();
            nex.pop();
            for(auto x:g[current]){
                if(color[x]==color[current]){
                    return false;
                }else if(color[x]==-1){
                    color[x]=color[current]^1;
                    nex.push(x);
                }
            }
        }
    }
    return true;
}

int main() {_ 
    int n,m,a,b;
    while(cin>>n){
        if(n==0){
            break;
        }
        cin>>m; 
        vector<vector<int>> g(n);
        fore(i,0,m){
            cin>>a>>b;
            g[a].pb(b);
            g[b].pb(a);
        }
        if(getAns(g)){
            cout<<"BICOLORABLE."<<ENDL;
        }else{
            cout<<"NOT BICOLORABLE."<<ENDL;
        }
        n++;

    }
    return 0;
}