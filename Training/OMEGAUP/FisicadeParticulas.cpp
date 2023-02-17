#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n,m,aux,tot=0;
    cin>>n>>m;
    while(n--){
        cin>>aux;
        if(aux==0){
            tot--;
        }else{
            tot++;
        }
    }
    if(abs(tot)>m){
        cout<<"Salvese quien pueda"<<ENDL;
    }else
    {
        cout<<"Todo bien"<<ENDL;
    }
    

    return 0;
}