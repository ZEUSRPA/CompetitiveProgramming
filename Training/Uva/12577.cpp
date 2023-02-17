#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    int c=1;
    while(cin>>s){
        if(s=="*"){
            break;
        }
        if(s=="Hajj"){
            cout<<"Case "<<c<<": "<<"Hajj-e-Akbar"<<ENDL;
        }else{
            cout<<"Case "<<c<<": "<<"Hajj-e-Asghar"<<ENDL;
        }
        c++;
    }
    return 0;
}