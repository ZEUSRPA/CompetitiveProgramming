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

int const MAXN=1e6;
int const MAXX=1e5+5;

struct Node{
    lli values[4];
    lli lazy;
    Node(){
        memset(values,0,sizeof(values));
        lazy=0;
    }
};

Node st[MAXN];

void getPermutation(int node, int offset){
    lli aux[4];
    fore(i,0,3){
        aux[i]=st[node].values[i];
    }
    fore(i,0,3){
        st[node].values[i]=aux[(i-offset+3)%3];
    }
}

void mergeInfo(int a, int b,int c){
    fore(i,0,3){
        st[c].values[i]=st[a].values[i]+st[b].values[i];
    }
}


void pushlazy(int node){
    st[2*node].lazy+=st[node].lazy;
    st[2*node+1].lazy+=st[node].lazy;
    st[node].lazy=0;
}

void build(int node, int s, int e){
    if(s==e){
        st[node].values[0]=1;
        return;
    }
    int mid=s+(e-s)/2;
    build(node*2,s,mid);
    build(node*2+1,mid+1,e);
    mergeInfo(node*2,node*2+1,node);
}

void update(int node, int s, int e, int l, int r){
    if(st[node].lazy!=0){
        if(s!=e){
            getPermutation(node,st[node].lazy%3);
            pushlazy(node);
        }else{
            // st[node]+=lazy[node];
            getPermutation(node,st[node].lazy%3);
            st[node].lazy=0;
        }
    }
    if(l<=s && e<=r){
        st[node].lazy++;
        if(s!=e){
            getPermutation(node,st[node].lazy%3);
            pushlazy(node);
        }else{
            getPermutation(node,st[node].lazy%3);
            // st[node].lazy=0;
        }
        st[node].lazy=0;
        return;
    }
    if(s>r || e<l){
        return ;
    }
    int mid = s+(e-s)/2;
    update(node*2,s,mid,l,r);
    update(node*2+1,mid+1,e,l,r);
    mergeInfo(node*2,node*2+1,node);
}

int query(int node, int s, int e, int l , int r){
    if(st[node].lazy!=0){
        if(s!=e){
            getPermutation(node,st[node].lazy%3);
            pushlazy(node);
        }else{
            // st[node]+=lazy[node];
            getPermutation(node,st[node].lazy%3);
            st[node].lazy=0;
        }
    }
    if(s>r || e<l){
        return 0;
    }
    if(l<=s && e<=r){
        return st[node].values[0];
    }
    int mid=s+(e-s)/2;
    int ans=query(node*2,s,mid,l,r)+query(node*2+1,mid+1,e,l,r);
    mergeInfo(node*2,node*2+1,node);
    return ans;
}

int main() {_ 
    int n,q,x,a,b;
    cin>>n>>q;
    build(1,0,n-1);
    while(q--){
        cin>>x>>a>>b;
        if(x==0){
            update(1,0,n-1,a,b);
        }else{
            cout<<query(1,0,n-1,a,b)<<ENDL;
        }
    }
    
    return 0;
}