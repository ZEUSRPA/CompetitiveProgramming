#include <bits/stdc++.h>
typedef long long int lli;
#define ENDL '\n'
using namespace std;
lli n;
vector<lli> arr;
vector<lli> st;
void pull(lli u){
    st[u]=min(st[2*u],st[2*u+1]);
}

void buildST(lli u,lli s,lli e){
    if(s==e){
        st[u]=arr[s];
        return;
    }
    lli m=(s+e)/2;
    buildST(2*u,s,m);
    buildST(2*u+1,m+1,e);
    pull(u);

}



void update(lli u, lli s,lli e,lli idx, lli val){
    if(s==e){
        st[u]=val;
        return;
    }
    lli m=(s+e)/2;
    if(idx<=m){
        update(2*u,s,m,idx,val);
    }else{
        update(2*u+1,m+1,e,idx,val);
    }
    pull(u);
}

lli query(lli u, lli s,lli e,lli l,lli r){
    if(s>r || e<l || e<s||l>r){
        return 1e18;
    }
    if(l<=s&&e<=r){
        return st[u];
    }else{
        lli m=(s+e)/2;
        return min(query(2*u,s,m,l,r),query(2*u+1,m+1,e,l,r));
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli q,aux;
    cin>>n>>q;
    arr.resize(n+1);
    st.resize(4*n);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    buildST(1,1,n);
    char t;
    lli l,r;
    while(q--){
        cin>>t>>l>>r;
        if(t=='u'){
            update(1,1,n,l,r);
        }else{
            cout<<query(1,1,n,l,r)<<ENDL;
        }
    }

    return 0;
}
