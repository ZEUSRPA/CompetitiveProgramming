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


int main() {_ 
    int n;
    cin>>n;
    vector<int> h(n);
    priority_queue<pair<int,int>> best;
    fore(i,0,n){
        cin>>h[i];
        best.push({h[i],i});
    }
    vector<pair<int,int>> ans(n,{0,INT_MAX});
    while(best.size()){
        auto current=best.top();
        best.pop();
        int dist=1;
        ans[current.second].second=0;
        int a=current.second+1;
        int b=current.second-1;
        bool other=true;
        while(other){
            other=false;
            if(a<ans.size()){
                if(ans[a].second>dist){
                    other=true;
                    ans[a].first++;
                    ans[a].second=dist;
                }
            }
            if(b>=0){
                if(ans[b].second>dist){
                    other=true;
                    ans[b].first++;
                    ans[b].second=dist;
                }
            }
            a++;
            b--;
            dist++;
        }
    }
    for(auto x:ans){
        cout<<x.first<<" ";
    }
    cout<<ENDL;
    return 0;
}