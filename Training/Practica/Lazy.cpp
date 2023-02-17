#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

map<lli,lli> st,lazy;
vector<lli> arr;

void pull(lli u){
    st[u]=(st[2*u]+st[2*u+1]);
}

void push(lli u, lli l, lli r){
    if(lazy[u]!=0){
        st[u]+=(r-l+1)*lazy[u];
        if(l!=r){
            lazy[2*u]+=lazy[u];
            lazy[2*u+1]+=lazy[u];
        }
        lazy[u]=0;
    }
}

void build(lli u,lli s,lli e){
    if(s==e){
        st[u]=arr[e];
        return;
    }
    lli m=(s+e)/2;
    build(2*u,s,m);
    build(2*u+1,m+1,e);
    pull(u);
}

void update(lli u,lli s,lli e,lli l,lli r, lli v){
    //push(u,s,e);
    if(r<s||e<l||e<s){
        return;
    }
    if(l<=s&&e<=r){
        lazy[u]+=v;
        //push(u,l,r);
        return;
    }
    lli m=(s+e)/2;
    update(2*u,s,m,l,r,v);
    update(2*u+1,m+1,e,l,r,v);
    //pull(u);
}

lli query(lli u,lli s,lli e,lli l,lli r){
    push(u,s,e);
    if(s>r||e<l||l>r){
        return 0;
    }
    if(l<=s&&e<=r){
        return st[u];
    }
    lli m=(s+e)/2;
    return (query(2*u,s,m,l,r)+query(2*u+1,m+1,e,l,r));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n,q,l,r,v;
    char o;
    cin>>n;
    arr.resize(n);
    for(lli i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1,0,n-1);
    cin>>q;
    while(q--){
        cin>>o;
        if(o=='u'){
            cin>>l>>r>>v;
            update(1,0,n-1,l,r,v);
        }else{
            cin>>l>>r;
            cout<<query(1,0,n-1,l,r)<<ENDL;
        }

    }
    return 0;
}
