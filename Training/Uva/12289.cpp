#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,o,w;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        o=0;
        w=0;
        if(s.size()==3){
            if(s[0]=='o'){
                o++;
            }else if(s[0]=='t'){
                w++;
            }
            if(s[1]=='n'){
                o++;
            }else if(s[1]=='w'){
                w++;
            }
            if(s[2]=='e'){
                o++;
            }else if(s[2]=='o'){
                w++;
            }
            if(o>w){
                cout<<1<<ENDL;
            }else{
                cout<<2<<ENDL;
            }
        }else{
            cout<<3<<ENDL;
        }
    }
    return 0;
}