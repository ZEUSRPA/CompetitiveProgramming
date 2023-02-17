#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

map<int,set<int>> tree;
vector<int> tourEuler;
vector<int> first;
vector<int> height;
map<int,int> lcaST;

void doTour(int u){
    if(first[u]==-1){
        first[u]=tourEuler.size();
    }
    tourEuler.push_back(u);
    if(height[u]==-1){
        height[u]=0;
    }
    for(auto x:tree[u]){
        height[x]=height[u]+1;
        doTour(x);
        tourEuler.push_back(u);
    }
}

void pull(int u){
    lcaST[u]=height[lcaST[2*u]]<height[lcaST[2*u+1]]?lcaST[2*u]:lcaST[2*u+1];
}

void buildST(int u, int s, int e){
    if(s==e){
        lcaST[u]=tourEuler[s];
        return;
    }
    int m=(s+e)/2;
    buildST(2*u,s,m);
    buildST(2*u+1,m+1,e);
    pull(u);
}

int getMin(int a,int b){
    if(a<height.size()){
        if(b<height.size()){
            return height[a]<height[b]?a:b;
        }else{
            return a;
        }
    }else{
        return b;
    }

}

int query(int u, int s, int e, int l, int r){
    if(s>r||e<l||s>e){ 
        return 1e9;
    }
    if(s>=l&&e<=r){
        return lcaST[u];
    }
    int m=(s+e)/2;
    return getMin(query(2*u,s,m,l,r),query(2*u+1,m+1,e,l,r));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,nodes,aux,q,l,r;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nodes;
        while(nodes--){
            cin>>aux;
            tree[i].insert(aux);
        }
    }
    height=vector<int> (n,-1);
    first=vector<int> (n,-1);
    doTour(0);
    buildST(1,0,tourEuler.size()-1);
    cin>>q;
    while(q--){
        cin>>l>>r;
        if(first[l]<first[r]){
            cout<<query(1,0,tourEuler.size()-1,first[l],first[r])<<ENDL;
        }else{
            cout<<query(1,0,tourEuler.size()-1,first[r],first[l])<<ENDL;
        }
    }
    return 0;
}