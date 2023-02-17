#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        lli aux=1;
        lli c=2;
        lli step=1;
        bool j=false;
        string s(a,'a');
        while(aux+1<=b){
            step++;
            if(aux+c<=b){
                aux+=c;
                j=true;
            }else{
                aux++;
                j=false;
                break;
            }
            
            c++;
        }
        s[a-step-1]='b';
        if(j){

            s[a-step]='b';
        }else{

            s[a-(b-aux)-1]='b';
        }
        cout<<s<<ENDL;
    }
    return 0;
}