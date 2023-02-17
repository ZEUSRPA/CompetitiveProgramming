#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,r,l,aux;
    cin>>t;
    while(t--){
        cin>>n;
        r=0;
        l=100;
        while(n--){
            cin>>aux;
            if(aux<l){
                l=aux;
            }
            if(aux>r){
                r=aux;
            }
        }
        cout<<2*(r-l)<<ENDL;
    }
    return 0;
}