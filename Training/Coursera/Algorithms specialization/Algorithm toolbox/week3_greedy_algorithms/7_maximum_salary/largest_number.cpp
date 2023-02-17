#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool s(string a, string b){
  int i=0;
  while(i<a.size() && i<b.size()){
    if(a[i]<b[i]){
      return false;
    }else if(a[i]>b[i]){
      return true;
    }
    i++;
  }
  int j=i-1;
  while(i<a.size()){
    if(a[i]<b[j]){
      return false;
    }else if(a[i]>b[j]){
      return true;
    }
    i++;
  }
  while(i<b.size()){
    if(a[j]<b[i]){
      return false;
    }else if(a[j]>b[i]){
      return true;
    }
    i++;
  }
  return true;
}

string largest_number(vector<string> a) {
  //write your code here
  sort(a.begin(),a.end(),s);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
