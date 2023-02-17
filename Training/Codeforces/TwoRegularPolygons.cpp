#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,m;
    cin>>t;
    for(int j=0;j<t;j++){
        cin>>n>>m;
        if(n%m==0){
            cout<<"YES"<<ENDL;
        }else
        {
            cout<<"NO"<<ENDL;
        }
        
    }
    return 0;
}