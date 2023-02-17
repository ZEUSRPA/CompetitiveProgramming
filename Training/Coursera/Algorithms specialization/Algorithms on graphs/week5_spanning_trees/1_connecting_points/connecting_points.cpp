#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.0;
  //write your code here
  priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> nex;
  vector<bool> visited(x.size(),false);
  nex.push({0.0,0});

  while(nex.size()){
    auto current=nex.top();
    nex.pop();
    if(!visited[current.second]){
      result+=current.first;
      visited[current.second]=true;
      for(int i=0;i<x.size();i++){
        if(i!=current.second && !visited[i]){
          double aux=double(x[current.second]-x[i])*double(x[current.second]-x[i])+double(y[current.second]-y[i])*double(y[current.second]-y[i]);
          aux=sqrt(aux);
          nex.push({aux,i});
        }
      }
    }
  }
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout<<fixed << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
