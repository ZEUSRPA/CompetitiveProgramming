#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,aux,div,cont;
    cin>>t;
    while(t--){
        cont=0;
        cin>>n;
        aux=n;
        while(aux>0){
            div=aux%10;
            aux/=10;
            if(div!=0&&n%div==0){
                cont++;
            }
        }
        cout<<cont<<ENDL;
    }
    return 0;
}