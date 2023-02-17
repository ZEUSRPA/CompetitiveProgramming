#include <bits/stdc++.h>
#define ENDL '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int n,m;
    cin>>n>>m;
    long long int aux=1ll<<n;
    if(n<=32){
        cout<<m%aux<<ENDL;
    }
    else{
        cout<<m<<ENDL;
    }
    return 0;
}