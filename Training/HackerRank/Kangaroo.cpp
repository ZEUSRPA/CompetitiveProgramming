#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x1,v1,x2,v2;
    cin>>x1>>v1>>x2>>v2;
    bool si=false;
    if(x1<=x2){
        if(v1>v2){
            if((x2-x1)%(v1-v2)==0){
                si=true;
            }
        }
    }else{
        if(v2>v1){
            if((x1-x2)%(v2-v1)==0){
                si=true;
            }
        }
    }
    cout<<(si?"YES":"NO")<<ENDL;
    return 0;
}