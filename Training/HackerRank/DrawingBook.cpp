#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,p,f,b;
    cin>>n>>p;
    f=p/2;
    if(n%2==0){
        b=(n-p)/2;
        b+=(n-p)%2;
    }else{
        b=(n-p)/2;
    }
    if(f<=b){
        cout<<f<<ENDL;
    }else{
        cout<<b<<ENDL;
    }
    return 0;
}