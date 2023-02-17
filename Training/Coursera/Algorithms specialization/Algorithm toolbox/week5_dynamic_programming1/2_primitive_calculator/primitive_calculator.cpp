#include <bits/stdc++.h>

using namespace std;
vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence;
  vector<int> dp(n+1,INT_MAX);
  dp[1]=0;
  int aux;
  for(int i=2;i<=n;++i){
    if(i-1>0){
      dp[i]=min(dp[i],dp[i-1]+1);
    }
    if(i%2==0){
      dp[i]=min(dp[i],dp[i/2]+1);
    }
    if(i%3==0){
      dp[i]=min(dp[i],dp[i/3]+1);
    }
  }
  int ans=n;
  while(ans!=1){
    sequence.push_back(ans);
    if(ans-1>0){
      if(dp[ans]==dp[ans-1]+1){
        ans=ans-1;
        continue;
      }
    }
    if(ans%2==0){
      if(dp[ans]==dp[ans/2]+1){
        ans=ans/2;
        continue;
      }
    }
    if(ans%3==0){
      if(dp[ans]==dp[ans/3]+1){
        ans=ans/3;
        continue;
      }
    }
  }
  sequence.push_back(1);
  reverse(sequence.begin(),sequence.end());

  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
