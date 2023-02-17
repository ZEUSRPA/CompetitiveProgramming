#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;



lli sum(lli n){
    lli aux;
    aux=(n%(1e9+7))*(n+1)*(2*n+1)/6;
    aux-=((n-1)*(n)*(2*n)/6);
    return aux;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t,n;
    cin>>t;

    while(t--){
        cin>>n;
        cout<<sum(n)<<ENDL;
    }
    
    return 0;
}