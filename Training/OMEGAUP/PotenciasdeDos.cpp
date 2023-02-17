#include <bits/stdc++.h>
#define ENDL '\n'

using namespace std;

string getValue(int n){
  string res="1";
  while(n--){
    string aux="";
    int carrier=0;
    int p=0;
    while(p<res.size()){
        int m=(2*(res[p]-'0')+carrier);
        aux+=(m%10)+'0';
        carrier=m/10;
        p++;
    }
    if(carrier>0){
        aux+=carrier+'0';
    }
    res=aux;
  }
  reverse(res.begin(),res.end());
  return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    cout<<getValue(n)<<ENDL;
    return 0;
}