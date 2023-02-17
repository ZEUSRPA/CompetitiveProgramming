#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    long long int dato,aux;
    while(t--){
        long long int cont=0;
        cin>>dato;
        while(dato>=10){
            aux=dato%10;
            dato/=10;
            cont+=dato*10;
            dato=dato+aux;
        }
        cont+=dato;
        cout<<cont<<ENDL;
    }

    return 0;
}
