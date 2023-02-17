#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

lli fX(lli n){
    return 2*n*n-12*n+7;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n,l,r,min=1e18;
    cin>>n;
    while(n--){
        cin>>l>>r;
        while(r-l>2){
            lli m1=l+(r-l)/3;
            lli m2=r-(r-l)/3;
            lli r1=fX(m1);
            lli r2=fX(m2);
            if(r2<r1){
                l=m1;
                min=r2;
            }
            else{
                r=m2;
                min=r1;
            }
        }
    }
    for(;l<=r;l++){
        if(fX(l)<min){
            min=fX(l);
        }
    }
    cout<<min<<ENDL;
    return 0;
}