#include <bits/stdc++.h>
#define ENDL '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,l1,r1,l2,r2;
    cin>>t;
    while(t--){
        cin>>l1>>r1>>l2>>r2;
        int ans=l1;
        if(r1>=l2&&r2>=l1){
            cout<<max(l2,l1)<<ENDL;
        }else{
            cout<<l1+l2<<ENDL;
        }
    }
    return 0;
}