#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,aux,c=1;
    bool si;
    cin>>t;
    while(t--){
        si=true;
        for(int i=0;i<3;i++){
            cin>>aux;
            if(aux>20){
                si=false;
            }
        }
        cout<<"Case "<<c<<": "<<(si?"good":"bad")<<ENDL;
        c++;
    }
    return 0;
}