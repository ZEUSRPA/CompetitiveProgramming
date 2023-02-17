#include <bits/stdc++.h>

using namespace std;

int optimal_weight(int W, const vector<int> &w) {

  vector<vector<int>> dp(w.size()+1,vector<int>(W+1,0));
  for(int i=1;i<=w.size();++i){
    for(int j=1;j<=W;++j){
      if(w[i-1]<=j){
        dp[i][j]=max(dp[i-1][j],w[i-1]+dp[i-1][j-w[i-1]]);
      }else{
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  return dp[w.size()][W];
}

int main() {
  int n, W;
  cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  cout << optimal_weight(W, w) << '\n';
}
