#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int l,r,maxi=0;
    cin>>l>>r;
    for(int i=l;i<=r;i++){
        for(int j=i;j<=r;j++){
            if((i^j)>maxi){
                maxi=(i^j);
            }
        }
    }
    cout<<maxi<<ENDL;
    return 0;
}