#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n,aux=0,change,minimo=0;
    cin>>n;
    while(n--){
        cin>>change;
        aux+=change;
        if(aux<minimo){
            minimo=aux;
        }
    }
    cout<<abs(minimo)+1<<ENDL;
    return 0;
}