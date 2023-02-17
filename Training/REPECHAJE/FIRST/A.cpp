#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int s,g;
    cin>>s>>g;
    int a=g;
    int b;
    while(true){
        b=s-a;
        if(b<1){
            cout<<-1<<ENDL;
            break;
        }
        if(b%g==0){
            if(__gcd(a,b)==g){
                cout<<a<<' '<<b<<ENDL;
                break;
            }
        }
        a+=g;
    }
    return 0;
}