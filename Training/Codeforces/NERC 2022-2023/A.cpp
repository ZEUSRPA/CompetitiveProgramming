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

map<int,lli> dp;
lli getAns(int n, int a, int b, int d,int pos){
    if(pos==n){
        return 0;
    }
    if(dp.count(pos)){
        return dp[pos];
    }
    lli ans=LLONG_MAX;
    if(pos>n){
         ans=min(ans,getAns(n,a,b,d,pos-1)+a);
    }else{
        ans=min(ans,getAns(n,a,b,d,pos+1)+a);
        ans=min(ans,getAns(n,a,b,d,pos+d)+b);
    }
    dp[pos]=ans;
    return dp[pos];
}

int main() {_ 
    int n,a,b,d;
    cin>>n>>a>>b>>d;
    cout<<getAns(n,a,b,d,0)<<ENDL;
    return 0;
}