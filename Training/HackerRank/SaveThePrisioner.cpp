#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,m,s,aux;
    cin>>t;
    while(t--){
        cin>>n>>m>>s;
        aux=(s+m-1)%n;
        cout<<(aux==0?n:aux)<<ENDL;
    }
    return 0;
}