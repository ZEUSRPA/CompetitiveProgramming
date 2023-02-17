#include<bits/stdc++.h>

using namespace std;

void dfs1(vector<vector<int>> &adj,stack<int>& pila,vector<bool> &visited,int x){
  visited[x]=true;
  for(auto y:adj[x]){
    if(!visited[y]){
      dfs1(adj,pila,visited,y);
    }
  }
  pila.push(x);
}

void dfs2(vector<vector<int>> &rev,vector<bool> &visited, int x){
  visited[x]=true;
  for(auto y:rev[x]){
    if(!visited[y]){
      dfs2(rev,visited,y);
    }
  }
}

vector<vector<int>> revGraph(vector<vector<int>> &adj){
  vector<vector<int>> rev(adj.size());
  for(int i=0;i<adj.size();++i){
    for(auto x:adj[i]){
      rev[x].push_back(i);
    }
  }
  return rev;
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  //write your code here
  stack<int> pila;
  vector<bool> visited(adj.size(),false);
  for(int i=0;i<adj.size();++i){
    if(!visited[i]){
      dfs1(adj,pila,visited,i);
    }
  }
  auto reversed =revGraph(adj);
  visited = vector<bool>(reversed.size(),false);
  while(pila.size()){
    int current = pila.top();
    pila.pop();
    if(!visited[current]){
      result++;
      dfs2(reversed,visited,current);
    }
  }
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
