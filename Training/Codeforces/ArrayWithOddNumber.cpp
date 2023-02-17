#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int aux,sum=0,aux2;
        bool in=false;
        bool par=false;
        cin>>aux;
        while(aux--){
            cin>>aux2;
            sum+=aux2;
            if(aux2%2){
                in=true;
            }else{
                par=true;
            }
        }
        if(sum%2==0){
            if(in && par){
                cout<<"YES"<<ENDL;
            }else{
                cout<<"NO"<<ENDL;
            }
        }else{
            cout<<"YES"<<ENDL;
        }

    }
    return 0;
}
