#include <bits/stdc++.h>
#define ENDL '\n'
#define FOR(a,b,c) for(int i=a;i<b;i+=c)
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,d,aux;
    cin>>n>>d;
    vector<int> nums(n);
    FOR(0,n,1){
        cin>>nums[i];
    }
    d%=n;
    FOR(0,n-1,1){
        aux=i+d;
        aux%=n;
        cout<<nums[aux]<<' ';
    }
    aux=n-1+d;
    aux%=n;
    cout<<nums[aux]<<ENDL;
    return 0;
}