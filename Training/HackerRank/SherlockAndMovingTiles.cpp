#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

lli l,s1,s2,q,a;

long double timeto(){
    long double dif=abs(s1-s2);
    lli area=l*l;
    area-=a;
    
    
    return 1e9+7;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>l>>s1>>s2>>q;
    while(q--){
        cin>>a;
        cout<<timeto()<<ENDL;
    }
    return 0;
}