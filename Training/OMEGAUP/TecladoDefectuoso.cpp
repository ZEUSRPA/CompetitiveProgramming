#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(cin>>s){
        for(auto &x:s){
            if(x=='_'){
                x=' ';
            }
        }
        cout<<s<<ENDL;
    }
    return 0;
}