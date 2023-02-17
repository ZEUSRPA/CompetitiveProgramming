#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,aux,sum=0;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        if(s=="donate"){
            cin>>aux;
            sum+=aux;
        }else{
            cout<<sum<<ENDL;
        }
    }
    return 0;
}