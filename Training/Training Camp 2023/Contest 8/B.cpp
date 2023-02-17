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

const lli mod = 1e9+7;

struct Node{
    lli mult;
    vector<lli> factors;

    Node(){
        mult=1;
        factors=vector<lli>(7,0);
    }
};

vector<Node> st;

vector<pair<lli,lli>> ranges;
vector<pair<lli,vector<lli>>> results;

vector<lli> fact(lli x){
    vector<lli> primes = {2,3,5,7,11,13,17};
    vector<lli> ans(7,0);
    lli pos=0;
    while(x!=1&&pos<primes.size()){
        while(x%primes[pos]==0){
            ans[pos]++;
            x/=primes[pos];
        }
        pos++;
    }
    return ans;
}

void plainTree(vector<vector<lli>>& g,vector<lli>& values,lli node){
    lli l=results.size();
    for(auto x:g[node]){
        plainTree(g,values,x);
    }
    lli r=results.size();
    results.pb({values[node],fact(values[node])});
    ranges[node]={l,r};
}

vector<lli> addFactors(vector<lli> &a, vector<lli> &b){
    vector<lli> ans(7);
    fore(i,0,7){
        ans[i]=((a[i]%mod)+(b[i]%mod))%mod;
    }
    return ans;
}

void build(lli node,lli s,lli e){
    if(s==e){
        st[node].factors=results[s].second;
        st[node].mult = (results[s].first)%mod;
        return ;
    }
    lli mid = s+(e-s)/2;
    build(node*2,s,mid);
    build(node*2+1,mid+1,e);
    st[node].mult=((st[node*2].mult%mod)*(st[node*2+1].mult)%mod)%mod;
    st[node].factors = addFactors(st[node*2].factors,st[node*2+1].factors);

}

void update(lli node,lli s, lli e, lli dx, lli val){
    if(s==e && dx==s){
        st[node].mult=((st[node].mult%mod)*(val%mod))%mod;
        auto vfacts=fact(val);
        st[node].factors=addFactors(st[node].factors,vfacts);
        return;
    }
    lli mid = s+(e-s)/2;
    if(dx<=mid){
        update(node*2,s,mid,dx,val);
    }else{
        update(node*2+1,mid+1,e,dx,val);
    }
    st[node].mult=((st[node*2].mult%mod)*(st[node*2+1].mult%mod))%mod;
    st[node].factors=addFactors(st[node*2].factors,st[node*2+1].factors);

}

Node query(lli node, lli s, lli e, lli l, lli r){
    if(r<s||l>e){
        return Node();
    }
    if(l<=s && e<=r){
        return st[node];
    }
    lli mid = s+(e-s)/2;
    auto q1=query(node*2,s,mid,l,r);
    auto q2=query(node*2+1,mid+1,e,l,r);
    q1.factors=addFactors(q1.factors,q2.factors);
    q1.mult=((q1.mult%mod)*(q2.mult%mod))%mod;
    return q1;
}

lli divisors(vector<lli> &factors){
    lli ans = 1;
    fore(i,0,7){
        ans=((ans%mod)*((factors[i]+1)%mod))%mod;
    }
    return ans%mod;

}

int main() {_ 
    lli n,u,v,q,x;
    cin>>n;
    st=vector<Node>(4*n+2);
    ranges = vector<pair<lli,lli>> (n);
    vector<vector<lli>> g(n);
    vector<lli> values(n);
    fore(i,0,n-1){
        cin>>u>>v;
        g[u].pb(v);
        // g[v].pb(u);
    }
    fore(i,0,n){
        cin>>values[i];
    }
    plainTree(g,values,0);
    build(1,0,n-1);
    cin>>q;
    string s;
    while(q--){
        cin>>s;
        if(s=="RAND"){
            cin>>u;
            auto ans=query(1,0,n-1,ranges[u].first,ranges[u].second);
            cout<<ans.mult<<" "<<divisors(ans.factors)<<ENDL;
        }else{
            cin>>u>>x;
            update(1,0,n-1,ranges[u].second,x);
        }
    }
    return 0;
}