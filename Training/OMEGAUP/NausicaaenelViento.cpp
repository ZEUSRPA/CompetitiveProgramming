#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    lli aux=0;
    for(auto x:s){
        if(isupper(x)){
            aux++;
        }else{
            aux--;
        }
    }
    bool up;
    if(aux>0){
        up=true;
    }else{
        up=false;
    }
    for(auto &x:s){
        if(up){
            x=toupper(x);
        }else{
            x=tolower(x);
        }
    }
    cout<<s<<ENDL;
    return 0;
}