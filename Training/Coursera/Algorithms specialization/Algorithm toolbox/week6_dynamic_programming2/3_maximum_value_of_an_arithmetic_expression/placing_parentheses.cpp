#include <bits/stdc++.h>

using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}



long long get_maximum_value(const string &exp) {
  //write your code here
  vector<long long> nums;
  vector<char> exps;
  exps.push_back('0');
  string aux="";
  for(auto x:exp){
    if(isdigit(x)){
      aux+=x;
    }else{
      exps.push_back(x);
      nums.push_back(stoll(aux));
      aux="";
    }
  }
  if(aux.size()){
    nums.push_back(stoll(aux));
  }
  vector<vector<long long >> m(nums.size()+1,vector<long long>(nums.size()+1,0));
  vector<vector<long long>> M(nums.size()+1,vector<long long>(nums.size()+1,0));
  int i=1;
  int j=1;
  while(i<=nums.size()){
    m[i][j]=nums[i-1];
    M[i][j]=nums[i-1];
    i++;
    j++;
  }
  for(int s=1;s<nums.size();++s){
    for(i=1;i<=nums.size()-s;i++){
      long long mi=1e18;
      long long Ma=-1e18;
      j=i+s;
      for(int k=i;k<j;k++){
        long long a=eval(M[i][k],M[k+1][j],exps[k]);
        long long b=eval(M[i][k],m[k+1][j],exps[k]);
        long long c=eval(m[i][k],M[k+1][j],exps[k]);
        long long d=eval(m[i][k],M[k+1][j],exps[k]);
        Ma=max(Ma,max(a,max(b,max(c,d))));
        mi=min(mi,min(a,min(b,min(c,d))));
      }
      M[i][j]=Ma;
      m[i][j]=mi;
      
    }
  }


  return M[1][nums.size()];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
