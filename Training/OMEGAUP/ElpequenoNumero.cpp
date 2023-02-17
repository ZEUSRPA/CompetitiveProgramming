#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        int tres=0;
        int once=0;
        bool sd=true;
        for(auto x:s){
            tres+=x-'0';
            if(sd){
                once+=x-'0';
            }else{
                once-=x-'0';
            }
            sd=!sd;
        }
        if(tres%3==0&&abs(once)%11==0&&(s[s.size()-1]-'0')%2==0){
            cout<<"Happy little demon"<<ENDL;
        }else
        {
            cout<<"Sad little demon"<<ENDL;
        }
        
    }
    return 0;
}