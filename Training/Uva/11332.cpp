#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

map<lli,lli> mem;

lli gn(lli n){
    if(mem.count(n)){
        return mem[n];
    }
    lli aux=0;
    lli fin=n;
    while(n!=0){
        aux+=n%10;
        n/=10;
    }
    if(aux>=10){
        aux=gn(aux);
    }
    mem[fin]=aux;
    return mem[fin];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n;
    while(cin>>n){
        if(n==0){
            break;
        }
        cout<<gn(n)<<ENDL;
    }
    return 0;
}