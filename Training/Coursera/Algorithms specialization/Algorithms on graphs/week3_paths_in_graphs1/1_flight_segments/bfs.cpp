#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  queue<int> next;
  next.push(s);
  int distance=0;
  vector<bool> visited(adj.size(),false);
  while(next.size()){
    int c=next.size();
    while(c--){
      int current=next.front();
      next.pop();
      if(current==t){
        return distance;
      }
      for(auto x:adj[current]){
        if(!visited[x]){
          visited[x]=true;
          next.push(x);
        }
      }
    }
    distance++;
  }
  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
