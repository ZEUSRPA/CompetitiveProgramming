#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n,m,res=1;
    cin>>n>>m;
    vector<lli> num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=n-1;i>0;i--){
        res*=abs(num[i-1]-num[i]);
        res%=m;
    }
    for(int i=n-2;i>0;i--){
        res*=abs(num[i]-num[i-1]);
        res%=m;
    }
    cout<<res<<ENDL;
    
    return 0;
}