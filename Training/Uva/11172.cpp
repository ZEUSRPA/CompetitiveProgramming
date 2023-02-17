#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a<b){
            cout<<"<"<<ENDL;
        }else if(a>b){
            cout<<">"<<ENDL;
        }else{
            cout<<"="<<ENDL;
        }
    }
    return 0;
}