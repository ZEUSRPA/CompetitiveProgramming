#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        int finalHeight=1;
        cin>>n;
        for(int i=0;i<n/2;i++){
            finalHeight=finalHeight*2+1;
        }
        if(n%2){
            finalHeight*=2;
        }
        cout<<finalHeight<<ENDL;
    }

    return 0;
}