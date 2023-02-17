#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,aux,tot,c=1;
    while(cin>>n){
        if(n==0){
            break;
        }
        tot=0;
        while(n--){
            cin>>aux;
            if(aux>0){
                tot++;
            }else{
                tot--;
            }
        }
        cout<<"Case "<<c<<": "<<tot<<ENDL;
        c++;
    }
    return 0;
}