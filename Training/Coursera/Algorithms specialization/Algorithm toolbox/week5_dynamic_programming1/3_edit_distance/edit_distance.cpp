#include <bits/stdc++.h>
using namespace std;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  return 0;
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  vector<vector<int>> dp(str1.size()+1,vector<int>(str2.size()+1,0));
  for(int i=1;i<=str1.size();i++){
    dp[i][0]=i;
  }
  for(int i=1;i<=str2.size();i++){
    dp[0][i]=i;
  }
  for(int i=1;i<=str1.size();++i){
    for(int j=1;j<=str2.size();++j){
      if(str1[i-1]==str2[j-1]){
        dp[i][j]=dp[i-1][j-1];
      }else{
        dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
      }
    }
  }
  int ans=dp[str1.size()][str2.size()];
  std::cout <<ans<< std::endl;
  return 0;
}
