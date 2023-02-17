#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,t=2,current=2;
    cin>>n;
    for(int i=1;i<n;i++){
        current=current*3/2;
        t+=current;
    }
    cout<<t<<ENDL;
    return 0;
}