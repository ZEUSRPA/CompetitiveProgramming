#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    lli n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n>2){
            if(n%2){
                cout<<n/2<<ENDL;
            }else
            {
                cout<<(n/2)-1<<ENDL;
            }
            
        }else{
            cout<<0<<ENDL;
        }
    }
    return 0;
}