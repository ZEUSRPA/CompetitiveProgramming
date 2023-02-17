#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t,n;
    string s;
    cin>>t;
    while(t--){
        string uno;
        string dos;
        bool d=false;
        cin>>n>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='2'){
                if(d){
                    uno+='0';
                    dos+='2';
                }else{
                    uno+='1';
                    dos+='1';
                }
            }else if(s[i]=='1'){
                if(d){
                    uno+='0';
                    dos+='1';
                    
                }else{
                    d=true;
                    uno+='1';
                    dos+='0';
                }
            }else{
                uno+='0';
                dos+='0';
            }
        }
        cout<<uno<<ENDL;
        cout<<dos<<ENDL;

    }
    return 0;
}