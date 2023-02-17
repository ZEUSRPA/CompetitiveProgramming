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


void getAns(vector<vector<int>>&g,vector<int> &degree){
    queue<int> nex;
    fore(i,1,degree.size()){
        if(degree[i]==0){
            nex.push(i);
        }
    }
    while(nex.size()){
        auto current = nex.front();
        nex.pop();
        cout<<current<<" ";
        for(auto x:g[current]){
            degree[x]--;
            if(degree[x]==0){
                nex.push(x);
            }
        }
    }

    cout<<ENDL;
}

int main() {_ 
    int n,m,a,b;
    while(cin>>n>>m){
        if(n==0&&m==0){
            break;
        }
        vector<vector<int>> g(n+1);
        vector<int> degree(n+1,0);
        fore(i,0,m){
            cin>>a>>b;
            g[a].pb(b);
            degree[b]++;
        }
        getAns(g,degree);
    }
    return 0;
}