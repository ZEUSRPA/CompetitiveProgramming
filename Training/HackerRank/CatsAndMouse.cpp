#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q,a,b,c,aux;
    cin>>q;
    while(q--){
        cin>>a>>b>>c;
        aux=abs(a-c);
        if(abs(b-c)<aux){
            cout<<"Cat B"<<ENDL;
        }else if(abs(b-c)==aux){
            cout<<"Mouse C"<<ENDL;
        }else{
            cout<<"Cat A"<<ENDL;
        }
    }
    return 0;
}