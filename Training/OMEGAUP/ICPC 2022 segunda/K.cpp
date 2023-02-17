#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ld long double
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;
 
struct Node{
    lli sum;
    lli sqrsum;
    lli lazy;
    Node(){
        sum=0;
        sqrsum=0;
        lazy=0;
    }
};
 
vector<lli> nums;
vector<Node> st;
lli mod=1e9+7;
 
void build(lli node, lli s, lli e){
    if(s==e){
        st[node].sum=nums[s]%mod;
        st[node].sum+=mod;
        st[node].sum%=mod;
        st[node].sqrsum=(nums[s]*nums[s])%mod;
        st[node].sqrsum+=mod;
        st[node].sqrsum%=mod;
        return;
    }
    lli mid=s+(e-s)/2;
    build(node*2,s,mid);
    build(node*2+1,mid+1,e);
    st[node].sum=st[node*2].sum+st[node*2+1].sum;
    st[node].sum+=mod;
    st[node].sum%=mod;
    st[node].sqrsum=st[node*2].sqrsum+st[node*2+1].sqrsum;
    st[node].sqrsum+=mod;
    st[node].sqrsum%=mod;
}
 
void update(lli node, lli s, lli e, lli l ,lli r, lli val){
    if(st[node].lazy!=0){
        
        st[node].sqrsum+=(st[node].sum*2LL*st[node].lazy)%mod+((e-s+1)*((st[node].lazy*st[node].lazy)%mod))%mod;
        st[node].sqrsum+=mod;
        st[node].sqrsum%=mod;
        st[node].sum+=((e-s+1)*st[node].lazy)%mod;
        st[node].sum+=mod;
        st[node].sum%=mod;
        if(s!=e){
            st[node*2].lazy+=st[node].lazy;
            st[node*2].lazy+=mod;
            st[node*2].lazy%=mod;
            st[node*2+1].lazy+=st[node].lazy;
            st[node*2+1].lazy+=mod;
            st[node*2+1].lazy%=mod;
        }
 
        st[node].lazy=0;
    }
    if(s>r||e<l||e<s){
        return;
    }
    if(l<=s&&e<=r){
        st[node].sqrsum+=((st[node].sum*2LL*val)%mod)+((e-s+1)*((val*val)%mod))%mod;
        st[node].sqrsum+=mod;
        st[node].sqrsum%=mod;
        st[node].sum+=((e-s+1)*val)%mod;
        st[node].sum+=mod;
        st[node].sum%=mod;
        if(s!=e){
            st[node*2].lazy+=val;
            st[node*2].lazy+=mod;
            st[node*2].lazy%=mod;
            st[node*2+1].lazy+=val;
            st[node*2+1].lazy+=mod;
            st[node*2+1].lazy%=mod;
        }
        return;
    }
    lli mid=s+(e-s)/2;
    update(node*2,s,mid,l,r,val);
    update(node*2+1,mid+1,e,l,r,val);
    st[node].sum=st[node*2].sum+st[node*2+1].sum;
    st[node].sum+=mod;
    st[node].sum%=mod;
    st[node].sqrsum=st[node*2].sqrsum+st[node*2+1].sqrsum;
    st[node].sqrsum+=mod;
    st[node].sqrsum%=mod;
 
}
 
lli query(lli node, lli s, lli e, lli l, lli r){
    if(st[node].lazy!=0){
        st[node].sqrsum+= ((st[node].sum*2LL*st[node].lazy) %mod) + ( (e-s+1) * ( (st[node].lazy*st[node].lazy) %mod ) ) %mod;
        st[node].sqrsum+=mod;
        st[node].sqrsum%=mod;
        st[node].sum+=((e-s+1)*st[node].lazy)%mod;
        st[node].sum+=mod;
        st[node].sum%=mod;
        if(s!=e){
            st[node*2].lazy+=st[node].lazy;
            st[node*2].lazy+=mod;
            st[node*2].lazy%=mod;
            st[node*2+1].lazy+=st[node].lazy;
            st[node*2+1].lazy+=mod;
            st[node*2+1].lazy%=mod;
        }
 
        st[node].lazy=0;
    }
    if(s>r||e<l||e<s){
        return 0;
    }
    if(l<=s&&e<=r){
        
        return st[node].sqrsum;
    }
 
    lli mid=s+(e-s)/2;
    lli one=query(node*2,s,mid,l,r);
    lli two=query(node*2+1,mid+1,e,l,r);
    lli result=(one+two)%mod;
    result+=mod;
    return result%mod;
}
 
int main()
{
    IO;
    lli n,q,l,r,x;
    cin>>n>>q;
    nums=vector<lli> (n+1);
    st=vector<Node> (4*n+4,Node());
 
    FOR(i,1,n+1){
        cin>>nums[i];
    }
    build(1,1,n);
    char c;
    while(q--){
        cin>>c;
        if(c=='u'){
            cin>>l>>r>>x;
            update(1,1,n,l,r,x);
        }else{
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<ENDL;
        }
    }
 
    return 0;
}