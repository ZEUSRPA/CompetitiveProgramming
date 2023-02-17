#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double a;
    lli c;
    cin>>a>>c;
    vector<lli> rad(c);
    for(int i=0;i<c;i++){
        cin>>rad[i];
    }
    sort(rad.begin(),rad.end());
    lli t=0;
    for(auto x:rad){
        double aux=M_PI*double(x*x);
        if(a-aux>=0){
            a-=aux;
            t++;
        }else{
            break;
        }
    }
    cout<<t<<ENDL;
    return 0;
}