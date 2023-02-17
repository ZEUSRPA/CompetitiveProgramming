#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    string country;
    int c=1;
    while(cin>>s){
        if(s=="#"){
            break;
        }
        if(s=="HELLO"){
            country="ENGLISH";
        }else if(s=="HOLA"){
            country="SPANISH";
        }else if(s=="HALLO"){
            country="GERMAN";
        }else if(s=="BONJOUR"){
            country="FRENCH";
        }else if(s=="CIAO"){
            country="ITALIAN";
        }else if(s=="ZDRAVSTVUJTE"){
            country="RUSSIAN";
        }else{
            country="UNKNOWN";
        }
        cout<<"Case "<<c<<": "<<country<<ENDL;
        c++;
    }
    return 0;
}