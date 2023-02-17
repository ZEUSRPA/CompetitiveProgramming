#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,b,h,w,p,a,aux;
    while(cin>>n){
        cin>>b>>h>>w;
        int mini=b+1;
        while(h--){
            cin>>p;
            for(int i=0;i<w;i++){
                cin>>a;
                if(a>=n){
                    aux=n*p;
                    if(aux<mini){
                        mini=aux;
                    }
                }
            }
        }
        if(mini<b){
            cout<<mini<<ENDL;
        }else{
            cout<<"stay home"<<ENDL;
        }
    }
    return 0;
}