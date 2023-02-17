#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

lli getValue(lli n,lli a,lli b,lli m,lli d){
    lli ms=n/(m+1);
    lli ma=n%(m+1);
    lli aux=a*ms*m+ms*b+d+a*ma;
    return aux;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t,d,m,x,a,b;
    cin>>t;
    
    while(t--){
        lli p=0;
        cin>>d>>a>>m>>b>>x;
        for(lli pot=1e9;pot>0;pot/=2){
            while(p+pot<1e9 && getValue(p+pot,a,b,m,d)<x){
                p+=pot;
            }
        }
        if(getValue(p,a,b,m,d)==x){
            cout<<p<<ENDL;
        }else{
            cout<<p+1<<ENDL;
        }
    }
    return 0;
}