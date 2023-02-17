#include <bits/stdc++.h>
#define ENDL '\n'

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
        int a=0,b=0;
        for(int i=0;i<3;++i){
            a+=s[i]-'0';
            b+=s[s.size()-i-1]-'0';
        }
        cout<<(a==b?"YES":"NO")<<ENDL;
    }
    return 0;
}