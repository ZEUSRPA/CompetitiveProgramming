#include <bits/stdc++.h>
#define ENDL '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int mod=1e8+9;
    long long int sum=0;
    long long int mul=1;
    vector<long long int> aux(5);
    for(int i=0;i<5;++i){
        cin>>aux[i];
        sum+=aux[i];
        sum%=mod;
        mul*=(aux[i]%mod);
        mul%=mod;
    }
    cout<<sum<<" "<<mul<<ENDL;
    return 0;
}