#include <bits/stdc++.h>
#define ENDL '\n'
typedef unsigned long long int lli;
using namespace std;


const lli MAX=1e4;
vector<bool> criba(MAX);
vector<lli> primos;
void doCriba(){
    for(lli i=0;i<MAX;i++){
        criba[i]=true;
    }
    criba[0]=false;
    criba[1]=false;
    for(lli i=2;i<MAX;i++){
        if(criba[i]){
            primos.push_back(i);
            for(lli j=i+i;j<MAX;j+=i){
                criba[j]=false;
            }
        }
    }
}

lli maxPrimes(lli n){
    lli cont=0;
    lli aux=1;
    lli i=0;
    while((aux*primos[i])<=n){
        cont++;
        aux*=primos[i];
        i++;
    }
    return cont;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    doCriba();
    lli q,n;
    cin>>q;
    while(q--){
        cin>>n;
        cout<<maxPrimes(n)<<ENDL;
    }
    return 0;
}