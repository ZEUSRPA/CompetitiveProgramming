#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    lli k,n,m;
    cin>>t;
    while(t--){
        cin>>k>>n>>m;
        lli a=n,b=m;
        for(int i=0;i<k-1;i++){
            a+=n;
            n=a-n;
            b+=m;
            m=b-m;
        }
        cout<<a<<" "<<b<<ENDL;
    }
    return 0;
}