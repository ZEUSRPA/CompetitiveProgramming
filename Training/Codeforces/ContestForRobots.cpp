#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,aux,cont,po=0,ot=0,tot=0;
    cin>>n;

    vector<int> p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        cin>>aux;
        if(aux==0 && p[i]==1){
            po++;
        }else if(aux==1 && p[i]==1){
            tot++;
        }else if(aux==1&&p[i]==0){
            ot++;
        }
    }
    int minimo;
    if(po==0){
        minimo=-1;
    }else{
        minimo=ceil(float(ot+1)/float(po));
    }
    cout<<minimo<<ENDL;
    return 0;
}