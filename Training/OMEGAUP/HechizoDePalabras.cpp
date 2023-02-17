#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
map<char,int> chars;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b,magia;
    string s;
    cin>>a>>b>>magia;
    while(a--){
        cin>>s;
        for(auto c:s){
            chars[c]++;
        }
    }
    while(b--){
        cin>>s;
        for(auto c:s){
            chars[c]--;
        }
    }
    for(auto x:chars){
        if(x.second<0){
            magia+=x.second;
        }
    }
    if(magia>0){
        cout<<"¡Magia hecha!"<<ENDL;
    }else
    {
        cout<<"Estudia de nuevo"<<ENDL;
    }
    
    return 0;
}