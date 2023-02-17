#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void min_heapify(int p){
    int left = 2*p;
    int right= 2*p+1;
    int smallest = left;
    if(left<=data_.size() && data_[left]<data_[p]){
      smallest=left;
    }else{
      smallest=p;
    }
    if(right<=data_.size() && data_[right]<data_[smallest]){
      smallest=right;
    }
    if(smallest!=p){
      swaps_.push_back({data_[p],data_[smallest]});
      std::swap(data_[p],data_[smallest]);
      min_heapify(smallest);
    }
  }

  void GenerateSwaps() {
    swaps_.clear();
    for(int i=data_.size()/2;i>=1;i--){
      min_heapify(i);
    }

  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
