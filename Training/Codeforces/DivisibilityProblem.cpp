#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a%b!=0){
            cout<<b-(a%b)<<ENDL;
        }else{
            cout<<0<<ENDL;
        }
    }
    return 0;
}