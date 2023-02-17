#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s,t;
    cin>>s>>t;
    int a=-1,b=-1;
    bool flag=false;
    for(int i=0;i<s.size();i++){
        if(s[i]!=t[i]){
            if(a==-1){
                a=i;
            }
            flag=true;
        }else{
            if(flag){
                b=i;
                flag=false;
            }
        }
    }
    if(flag){
        b=t.size();
    }
    if(a!=-1){
        reverse(t.begin()+a,t.begin()+b);
    }
    if(s==t){
        cout<<"YES"<<ENDL;
    }else{
        cout<<"NO"<<ENDL;
    }
    return 0;
}