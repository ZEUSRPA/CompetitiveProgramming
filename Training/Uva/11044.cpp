#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,m,r;
    cin>>t;
    while(t--){
        cin>>n>>m;
        n-=2;
        m-=2;
        if(n%3){
            n=n/3+1;
        }else{
            n/=3;
        }
        if(m%3){
            m=m/3+1;
        }else{
            m/=3;
        }
        cout<<n*m<<ENDL;
    }
    return 0;
}