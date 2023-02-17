#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        n*=(567/9);
        n+=7492;
        n*=(235/47);
        n-=498;
        n/=10;
        cout<<abs(n%10)<<ENDL;
    }
    return 0;
}