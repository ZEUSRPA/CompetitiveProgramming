#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    bool f=true;
    while(cin>>s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='"'){
                if(f){
                    s[i]='`';
                    s.insert(s.begin()+i,'`');

                    f=false;
                }else{
                    s[i]='\'';
                    s.insert(s.begin()+i,'\'');
                    f=true;
                }
                i++;
            }
        }
        cout<<s<<ENDL;
    }
    return 0;
}