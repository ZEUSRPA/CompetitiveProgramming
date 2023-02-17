#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

std::pair<int,int> partition3(vector<int> &a, int l, int r){
  std::pair<int,int> res;
  int x=a[l];
  res.first=l;
  res.second=l;
  for(int i=l+1;i<=r;i++){
    if(a[i]==x){
      res.second++;
      swap(a[i],a[res.second]);
    }else if(a[i]<x){
      swap(a[i],a[res.first]);
      swap(a[i],a[res.second+1]);
      res.first++;
      res.second++;
    }
  }
  return res;

}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  auto m = partition3(a, l, r);
  if(m.first>0){
    randomized_quick_sort(a, l, m.first-1);
  }
  if(m.second<a.size()-1){
    randomized_quick_sort(a, m.second+1, r);
  }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
