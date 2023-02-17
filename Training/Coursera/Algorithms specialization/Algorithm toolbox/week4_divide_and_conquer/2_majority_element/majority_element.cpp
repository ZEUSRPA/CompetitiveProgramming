#include <bits/stdc++.h>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  // if (left == right) return -1;
  // if (left + 1 == right) return a[left];
  //write your code here

  return -1;
}

int main() {
  int n,aux;
  std::cin >> n;
  std::unordered_map<int,int> a;
  for (size_t i = 0; i < n; ++i) {
    std::cin >> aux;
    a[aux]++;
  }
  int res=0;
  for(auto x:a){
    if(x.second>=n/2+1){
      res=1;
      break;
    }
  }
  std::cout << res<< '\n';
}
