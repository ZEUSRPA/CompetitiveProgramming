#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  vector<int> colors(adj.size(),-1);
  queue<int> next;
  for(int i=0;i<adj.size();++i){
    if(colors[i]==-1){
      colors[i]=0;
      next.push(i);
      while(next.size()){
        int current=next.front();
        next.pop();
        for(auto x:adj[current]){
          if(colors[x]==-1){
            colors[x]=(colors[current]==0?1:0);
            next.push(x);
          }else if(colors[current]==colors[x]){
            return 0;
          }
        }
      }
    }
  }

  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
