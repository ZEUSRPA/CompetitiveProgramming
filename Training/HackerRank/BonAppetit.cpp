#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,aux,tot=0,b;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>aux;
        if(i!=k){
            tot+=aux;
        }
    }
    cin>>b;
    if(b==tot/2){
        cout<<"Bon Appetit"<<ENDL;
    }else{
        cout<<b-(tot/2)<<ENDL;
    }
    return 0;
}