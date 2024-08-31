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
vector<lli> value;

lli const MAXN=510;
lli dp[MAXN];

lli getDp(lli val){
    if(val<value.size()){
        return value[val];
    }
    if(dp[val]!=-1){
        return dp[val];
    }
    lli ans=LLONG_MAX;

    fore(i,1,sz(value)){
        ans=min(ans,getDp(val-i)+value[i]);
    }
    dp[val]=ans;
    return dp[val];

}

lli getAns(lli a){
    if(a<value.size()){
        return value[a];
    }
    lli ans=LLONG_MAX;
    
    if(a>500){
        fore(i,1,sz(value)){
            lli aux=(a-500)/i;
            lli cu=a-aux*i;
            lli current=aux*value[i];
            current+=getDp(cu);
            ans=min(ans,current);
        }
    }else{
        ans=getDp(a);
    }
    return ans;
}

int main() {_
    lli n,q,a;
    cin>>n>>q;
    memset(dp,-1,sizeof(dp));
    value.resize(n+1);
    fore(i,1,n+1){
        cin>>value[i];
    }
    while(q--){
        cin>>a;
        cout<<getAns(a)<<ENDL;
    }
    return 0;
}