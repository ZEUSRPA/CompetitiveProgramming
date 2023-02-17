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

const lli MAXN=1e6+10;

lli values[MAXN];
unordered_map<lli,lli> dp;

lli getAns(lli val){
    if(val==1){
        return 1;
    }
    if(dp.count(val)){
        return dp[val];
    }
    lli ans=1;
    if(val%2==1){
        ans+=getAns(3*val+1);
    }else{
        ans+=getAns(val/2);
    }
    if(val<MAXN){
        values[val]=ans;
    }
    dp[val]=ans;
    return dp[val];
}

lli st[4*MAXN];

void build(lli node, lli s, lli e){
    if(s==e){
        st[node]=values[s];
        return;
    }
    lli mid=s+(e-s)/2;
    build(node*2,s,mid);
    build(node*2+1,mid+1,e);
    st[node] = max(st[node*2],st[node*2+1]);
}

lli query(lli node, lli s, lli e, lli l, lli r){
    if(l<=s && e<=r){
        return st[node];
    }
    if(s>r||e<l){
        return LLONG_MIN;   
    }
    lli mid=s+(e-s)/2;
    return max(query(node*2,s,mid,l,r),query(node*2+1,mid+1,e, l,r));
}

int main() {_ 
    lli l,r;
    for(lli i=1e6;i>0;i--){
        getAns(i);
    }
    values[1]=1;
    build(1,1,1e6);
    while(cin>>l>>r){
        cout<<l<<" "<<r<<" "<<query(1,1,1e6,min(l,r),max(l,r))<<ENDL;
    }
    return 0;
}