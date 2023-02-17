#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;

  
};
bool s(Segment a, Segment b){
  if(a.end>b.end){
    return false;
  }else{
    return true;
  }
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  sort(segments.begin(),segments.end(),s);
  for(int i=0;i<segments.size();++i){
    for(int j=i+1;j<segments.size();++j){
      if(segments[j].start<=segments[i].end){
        segments.erase(segments.begin()+j);
        j--;
      }
    }
  }
  for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].end);
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
