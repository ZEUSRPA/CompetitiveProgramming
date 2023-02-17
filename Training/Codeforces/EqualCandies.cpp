#include <bits/stdc++.h>
#define ENDL '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,aux;
    cin>>t;
    while(t--){
        cin>>n;
        int minimo=INT_MAX;
        int total=0;
        for(int i=0;i<n;++i){
            cin>>aux;
            minimo=min(minimo,aux);
            total+=aux;
        }

        cout<<total-(minimo*n)<<ENDL;
    }
    return 0;
}