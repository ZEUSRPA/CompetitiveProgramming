#include <bits/stdc++.h>
#define ENDL '\n'
#define FOR(i,a,n) for(int i=(a);i<(n);i++)
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,x,y;
    string s;
    cin>>t;
    while(t--){
        vector<int> orders(4,0);
        bool si=true;
        cin>>x>>y;
        cin>>s;
        for(auto x:s){
            if(x=='U'){
                orders[0]++;
            }else if(x=='D'){
                orders[1]++;
            }else if(x=='R'){
                orders[2]++;
            }else{
                orders[3]++;
            }
        }
        if(x>0){
            if(orders[2]<x){
                si=false;
            }
        }else{
            if(orders[3]<abs(x)){
                si=false;
            }
        }

        if(y>0){
            if(orders[0]<y){
                si=false;
            }
        }else{
            if(orders[1]<abs(y)){
                si=false;
            }
        }
        cout<<(si?"YES":"NO")<<ENDL;
    }
    return 0;
}