#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

map<lli,lli> st;
vector<lli> arr;

void pull(lli u){
    st[u]=min(st[2*u],st[2*u+1]);
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

lli query(lli u,lli s,lli e,lli l,lli r){
    if(s>r||e<l||l>r){
        return 1e18;
    }
    if(l<=s&&e<=r){
        return st[u];
    }
    lli m=(s+e)/2;
    return min(query(2*u,s,m,l,r),query(2*u+1,m+1,e,l,r));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n,q,l,r;
    cin>>n;
    arr.resize(n);
    for(lli i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1,0,n-1);
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<query(1,0,n-1,l,r)<<ENDL;
    }
    return 0;
}
