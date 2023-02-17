#include <bits/stdc++.h>

using namespace std;

int partition3(vector<int> &A) {
  //write your code here
  int target=0;
  for(int i=0;i<A.size();++i){
    target+=A[i];
  }
  if(target%3){
    return 0;
  }
  target/=3;
  sort(A.begin(),A.end());
  for(int i=0;i<A.size();++i){
    int l=i+1,r=A.size()-1;
    bool si=false;
    while(l<r){
      if(A[l]==-1){
        l++;
        continue;
      }
      if(A[r]==-1){
        r--;
        continue;
      }
      if(A[i]+A[l]+A[r]==target){
        si=true;
        A[l]=-1;
        A[r]=-1;
        break;
      }  
    }
    if(!si){
      return 0;
    }
  }
  return 1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
