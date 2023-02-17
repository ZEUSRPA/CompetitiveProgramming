#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n;
    set<int> neck;
    set<int> brac;
    cin>>t;
    while(t--){
        neck.clear();
        brac.clear();
        cin>>n;
        int aux;
        for(int i=0;i<n;i++){
              cin>>aux;
              neck.insert(aux);
        }
        for(int i=0;i<n;i++){
              cin>>aux;
              brac.insert(aux);
        }
        int cont=1;
        for(auto x:neck){
            cout<<x;
            if(cont==n){
                cout<<ENDL;
            }else{
                cout<<" ";
            }
            cont++;
        }
        cont=1;
        for(auto x:brac){
            cout<<x;
            if(cont==n){
                cout<<ENDL;
            }else{
                cout<<" ";
            }
            cont++;
        }

    }
    return 0;
}