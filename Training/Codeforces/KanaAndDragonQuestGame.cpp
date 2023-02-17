#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,x,m,n;
    cin>>t;
    while(t--){
        bool si=false;
        cin>>x>>n>>m;
        while(n--){
            if((x-(m*10))<=0){
                si=true;
                break;
            }
            x=x/2+10;
        }
        if((x-(m*10))<=0){
            si=true;
        }
        cout<<(si?"YES":"NO")<<ENDL;
    }
    return 0;
}