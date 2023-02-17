#include <bits/stdc++.h>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  vector<pair<double, int>> auxi;
  for(int i=0;i<weights.size();++i){
    auxi.push_back(make_pair(float(values[i]/(float)weights[i]),weights[i]));
  }
  sort(auxi.rbegin(),auxi.rend());
  for(int i=0;i<auxi.size();++i){
    if(auxi[i].second<=capacity){
      value+=auxi[i].first*auxi[i].second;
      capacity-=auxi[i].second;
    }else{
      value+=auxi[i].first*capacity;
      break;
    }

  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
