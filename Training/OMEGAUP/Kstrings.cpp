#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    int min=1e9;
    cin>>s;
    map<char,int> let;
    for(auto x:s){
        let[x]++;
    }
    for(auto x:let){
        if(x.second<min){
            min=x.second;
        }
    }
    cout<<1;
    for(int i=2;i<=min;i++){
        bool s=true;
        for(auto x:let){
            if(x.second%i!=0){
                s=false;
                break;
            }
        }
        if(s){
            cout<<" "<<i;
        }
    }
    cout<<ENDL;
    return 0;
}