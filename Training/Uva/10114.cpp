#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int d,dr;
    double dp,a;
    int aux;
    double aux2;
    while(cin>>d>>dp>>a>>dr){
        if(d<0){
            break;
        }
        map<int,double> depreciation;
        while(dr--){
            cin>>aux>>aux2;
            depreciation[aux]=aux2;
        }
        double c=0.0,w=a+dp,pm=a/double(d);
        int r=0;

        for(int i=0;i<=d;i++){
            if(depreciation.count(i)){
                c=depreciation[i];
            }
            w-=w*c;
            if(w>a){
                if(r==1){
                    cout<<r<<" month"<<ENDL;
                }else{
                    cout<<r<<" months"<<ENDL;
                }
                break;
            }
            a-=pm;
            r++;

        }
        
    }
    return 0;
}