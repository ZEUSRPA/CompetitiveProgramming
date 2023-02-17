#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
map<int,map<int,int>> tree;
priority_queue<pair<int,int>> total;

void dfs(int node,int tot){
    int cont=0;
    for(auto &x:tree[node]){
        if(x.second==0){
            x.second=1;
            cont++;
            dfs(x.first,tot+1);
        }
    }
    if(cont==0){
        total.push(make_pair(tot,1));
        return;
    }
}

int getMax(int k){
    int aux=0;
    dfs(1,0);
    if(total.size()<k){
        int dif=k-total.size();
        while(dif--){
            auto a=total.top();
            total.pop();
            a.first--;
            a.second++;
            total.push(a);
        }
    }
    for(int i=0;i<k;i++){
        auto a=total.top();
        total.pop();
        aux+=a.first*a.second;
    }
    return aux;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,u,v;
    cin>>n>>k;
    n--;
    while(n--){
        cin>>u>>v;
        tree[u][v];
        tree[v][u];
    }
    cout<<getMax(k)<<ENDL;
    return 0;
}