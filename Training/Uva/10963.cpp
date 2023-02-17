#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,w,n,s;
    cin>>t;
    while(t--){
        bool si=true;
        int aux=-1;
        cin>>w;
        while(w--){
            cin>>n>>s;
            if(aux==-1){
                aux=n-s;
            }else{
                if(n-s!=aux){
                    si=false;
                }
            }
        }
        cout<<(si?"yes":"no")<<ENDL;
        if(t!=0){
            cout<<ENDL;
        }
    }
    return 0;
}