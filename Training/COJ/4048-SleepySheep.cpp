#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;



int valid(string &p){
    bool valido=false;
    int cont=0;
    char aux;
    while(!valido){
        valido=true;
        aux=p[0];
        for(int i=1;i<p.size();i++){
            if((p[i]=='<'&&aux=='>')){
                valido=false;
                swap(p[i],p[i-1]);
                cont++; 
            }
            aux=p[i];
        }
    }
    return cont;
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,s;
    string p;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>p;
        cout<<valid(p)<<ENDL;
    }
    return 0;
}