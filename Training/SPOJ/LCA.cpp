#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

map<int,set<int>> tree;
vector<int> tourEuler;
vector<int> first;
vector<int> height;
map<int, int> lcaSTree;



void doEulersTour(int i){
    if(first[i]==-1){
        first[i]=tourEuler.size();
    }
    if(height[i]==-1){
        height[i]=0;
    }
    tourEuler.push_back(i);
    for(auto x:tree[i]){
        height[x]=height[i]+1;
        doEulersTour(x);
        tourEuler.push_back(i);
    }
}

void pull(int u){
    int aux1=height[lcaSTree[2*u]-1];
    int aux2=height[lcaSTree[2*u+1]-1];
    if(aux1<aux2){
        lcaSTree[u]=lcaSTree[2*u];
    }else{
        lcaSTree[u]=lcaSTree[2*u+1];
    }
}

void doSegmentLCA(int u, int s, int e){
    if(s==e){
        lcaSTree[u]=tourEuler[s]+1;
        return;
    }
    int m=(s+e)/2;
    doSegmentLCA(2*u,s,m);
    doSegmentLCA(2*u+1,m+1,e);
    pull(u);
}

void doLCA(int n){
    first=vector<int>(n,-1);
    height=vector<int>(n,-1) ;
    tourEuler.clear();
    lcaSTree.clear();
    doEulersTour(0);
    doSegmentLCA(1,0,tourEuler.size()-1);

}

int lca(int u,int s,int e,int l, int r){
    if(s>r||e<l||s>e){
        return 1e9;
    }
    if(s>=l && e<=r){
        return lcaSTree[u];
    }
    int m=(s+e)/2;
    return min(lca(2*u,s,m,l,r),lca(2*u+1,m+1,e,l,r));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,nodes,aux,q,z=1;
    cin>>t;
    while(z<=t){
        cin>>n;
        tree.clear();
        for(int i=0;i<n;i++){
            cin>>nodes;
            for(int j=0;j<nodes;j++){
                cin>>aux;
                tree[i].insert(aux-1);
            }
        }
        doLCA(n);
        cin>>q;
        cout<<"Case "<<z<<":"<<ENDL;
        int v,w;
        while(q--){
            cin>>v>>w;
            int l,r;
            if(first[v-1]<first[w-1]){
                l=first[v-1];
                r=first[w-1];
            }else
            {
                l=first[w-1];
                r=first[v-1];
            }
            
            cout<<lca(1,0,tourEuler.size()-1,l,r)<<ENDL;
        }
        z++;
    }
    return 0;
}