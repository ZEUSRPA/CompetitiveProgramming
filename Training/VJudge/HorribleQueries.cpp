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

// const lli MAXN=1e7;

struct Node{
    lli lazy;
    lli value;
    Node(){
        lazy=0;
        value=0;
    }
};

vector<Node> st;

void pushLazy(int node){
    st[node*2].lazy+=st[node].lazy;
    st[node*2+1].lazy+=st[node].lazy;
    st[node].lazy=0;
}

void update(int node, int s, int e, int l, int r,lli val){
    if(st[node].lazy!=0){
        if(s!=e){
            st[node].value+=(st[node].lazy*(e-s+1));
            pushLazy(node);
        }else{
            st[node].value+=st[node].lazy;
            st[node].lazy=0;
        }
    }
    if(l<=s && e<=r){
        if(s!=e){
            st[node].lazy=val;
            pushLazy(node);
            st[node].value+=((e-s+1)*val);
        }else{
            st[node].value+=val;
            st[node].lazy=0;
        }
        return;
    }
    if(s>r || e<l){
        return;
    }
    int mid=s+(e-s)/2;
    update(node*2,s,mid,l,r,val);
    update(node*2+1,mid+1,e,l,r,val);
    st[node].value=st[node*2].value+st[node*2+1].value;

}

lli query(int node, int s, int e, int l, int r){
    if(st[node].lazy!=0){
        if(s!=e){
            st[node].value+=(st[node].lazy*(e-s+1));
            pushLazy(node);
        }else{
            st[node].value+=st[node].lazy;
            st[node].lazy=0;
        }
    }
    if(l<=s && e<=r){
        return st[node].value;
    }
    if(s>r||e<l){
        return 0;
    }
    int mid=s+(e-s)/2;
    lli ans = query(node*2,s,mid,l,r)+query(node*2+1,mid+1,e,l,r);
    st[node].value=st[node*2].value+st[node*2+1].value;
    return ans;
}

int main() {_ 
    lli t,n,c,q,a,b,v;
    cin>>t;
    while(t--){
        cin>>n>>c;
        st=vector<Node>(4*n+10,Node());
        // deb(st[0].lazy);
        while(c--){
            cin>>q;
            if(q==0){
                cin>>a>>b>>v;
                update(1,1,n,a,b,v); 
            }else{
                cin>>a>>b;
                cout<<query(1,1,n,a,b)<<ENDL;
            }
        }

    }
    return 0;
}