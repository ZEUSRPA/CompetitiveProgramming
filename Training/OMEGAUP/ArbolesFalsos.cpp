#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
map<lli,set<lli>> tree;
map<lli,int> status;

lli cutTrees(lli n){
    status[n]=1;
    lli cont=0;
    for(auto x:tree[n]){
        if(status[x]==0){
            cont+=cutTrees(x);
        }else if(status[x]==1){
            cont=1;
        }
    }
    if(cont>0){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n,m,a,b;
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        tree[a].insert(b);
        tree[b].insert(a);
    }
    lli cont=0;
    for(auto x:tree){
        if(status[x.first]==0){
            cont+=cutTrees(x.first);
        }
    }
    cout<<cont<<ENDL;
    return 0;
}