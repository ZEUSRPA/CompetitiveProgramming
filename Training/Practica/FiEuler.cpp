#include<bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

const lli MAX=1e5+1;

bool criba[MAX];
vector<lli> primos;

void doCriba(){
    for(lli x=1;x<=MAX-1;x++){
        criba[x]=true;
    }
    criba[1]=false;
    lli i=2;
    for(;i*i<=MAX-1;i++){
        if(criba[i]){
            primos.push_back(i);
            for(lli j=i+i;j<=MAX-1;j+=i){
                criba[j]=false;
            }
        }
    }
    for(;i<MAX-1;i++){
        if(criba[i]){
            primos.push_back(i);
        }
    }
}

lli fi(lli n){
    if(n==1){
        return 0;
    }
    map<lli,lli> factores;
    lli i=0,phi,aux=n;

    while(n!=1 && i<primos.size()){
        while(n%primos[i]==0){
            factores[primos[i]]++;
            n/=primos[i];
        }
        i++;
    }
    if(n>1){
        factores[n]++;
    }
    lli div=1,sum=1;

    for(auto x:factores){
        div*=x.first;
        sum*=x.first-1;
    }
    phi=(aux*sum)/div;
    return phi;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n;
    doCriba();
    while(cin>>n){
        if(n==0)
            break;
        cout<<fi(n)<<ENDL;
    }
    return 0;
}
