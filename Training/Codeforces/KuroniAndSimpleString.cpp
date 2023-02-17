#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<int> pos;
    string s;
    cin>>s;
    int l=0,r=s.size()-1;
    bool lef=true,ri=true;
    while(l<=r){
        if(lef && s[l]=='('){
            lef=false;
        }
        if(ri && s[r]==')'){
            ri=false;
        }
        if(!lef && !ri){
            pos.insert(l);
            pos.insert(r);
            lef=true;
            ri=true;
        }
        if(lef){
            l++;
        }
        if(ri){
            r--;
        }
    }
    if(pos.size()>0){
        cout<<1<<ENDL;
    }
    cout<<pos.size()<<ENDL;
    int aux=1;
    for(auto x:pos){
        cout<<x+1;
        if(aux==s.size()){
            cout<<ENDL;
        }else
        {
            cout<<" ";
        }
    }
    return 0;
}