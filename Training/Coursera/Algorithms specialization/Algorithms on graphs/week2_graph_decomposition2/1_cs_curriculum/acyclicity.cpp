#include <bits/stdc++.h>

using namespace std;

int acyclic(vector<vector<int> > &adj,vector<bool> &visited,vector<bool> &deleted,int p=0) {
  //write your code here
  visited[p]=true;
  bool ending=true;
  for(auto x:adj[p]){
    if(!deleted[x]){
      if(!visited[x]){
        ending= false;
        if(acyclic(adj,visited,deleted,x)){
          return 1;
        }
      }else{
        return 1;
      }
    }
  }
  if(!ending){
    visited[p]=false;
  }else{
    deleted[p]=true;
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<bool> visited(adj.size()+1,false);
  vector<bool> deleted(adj.size()+1,false);
  int ans=0;
  for(int i=0;i<adj.size();++i){
    if(!deleted[i]){
      if(acyclic(adj,visited,deleted,i)){
        ans=1;
        break;
      }
    }
  }
  std::cout << ans;
}
