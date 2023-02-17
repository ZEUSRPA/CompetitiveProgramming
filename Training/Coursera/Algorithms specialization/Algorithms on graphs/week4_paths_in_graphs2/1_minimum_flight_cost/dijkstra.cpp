#include <bits/stdc++.h>

using namespace std;

long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
  vector<long long> dijkstra (adj.size(),LLONG_MAX);
  dijkstra[s]=0;
  vector<bool> visited(adj.size(),false);
  priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
  pq.push({0,s});
  while(pq.size()){
    auto current=pq.top();
    pq.pop();
    if(!visited[current.second]){
      visited[current.second]=true;
      for(int i=0;i<adj[current.second].size();++i){
        dijkstra[adj[current.second][i]]=min(dijkstra[adj[current.second][i]],dijkstra[current.second]+cost[current.second][i]);
        pq.push({dijkstra[adj[current.second][i]],adj[current.second][i]});
      }
    }
  }
  
  return (dijkstra[t]==LLONG_MAX?-1:dijkstra[t]);
  
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
