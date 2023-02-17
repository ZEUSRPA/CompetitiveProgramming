#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,aux,maximo,minimo,contm=0,cont=0;
    cin>>n;
    cin>>maximo;
    minimo=maximo;
    for(int i=0;i<n-1;i++){
        cin>>aux;
        if(aux>maximo){
            contm++;
            maximo=aux;
        }else if(aux<minimo){
            cont++;
            minimo=aux;
        }
    }
    cout<<contm<<" "<<cont<<ENDL;
    return 0;
}