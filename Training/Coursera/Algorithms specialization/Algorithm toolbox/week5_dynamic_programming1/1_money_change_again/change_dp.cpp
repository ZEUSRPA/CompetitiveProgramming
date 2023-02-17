#include <bits/stdc++.h>
using namespace std;
int get_change(int m) {
  //write your code here
  return m / 4;
}

int main() {
  int m;
  cin >> m;
  vector<int> dp(m+1,INT_MAX);
  vector<int> coins{1,3,4};
  dp[0]=0;
  for(int i=1;i<=m;++i){
    for(auto x:coins){
      if(i>=x){
        dp[i]=min(dp[i],dp[i-x]+1);
      }
    }
  }

  cout << dp[m] << '\n';
}
