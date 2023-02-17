#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,f,s,a,e;
    cin>>t;
    while(t--){
        int r=0;
        cin>>f;
        while(f--){
            cin>>s>>a>>e;
            r+=s*e;
        }
        cout<<r<<ENDL;
    }
    return 0;
}