#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long int aux[4];
        long long int sum=0;
        long long int res=0;
        bool si=true;
        for(int i=0;i<4;i++){
            cin>>aux[i];
            sum+=aux[i];
        }
        if(sum%3==0){
            sum=sum/3;
            for(int i=0;i<3;i++){
                if(sum>=aux[i]){
                    res+=sum-aux[i];
                }else{
                    si=false;
                }
            }
            if(res!=aux[3]){
                si=false;
            }
        }else{
            si=false;
        }
        cout<<(si?"YES":"NO")<<ENDL;

    }
    return 0;
}
