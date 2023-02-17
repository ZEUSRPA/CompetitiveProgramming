#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

lli minD(string s){
    vector<lli> rs;
    lli max=0,aux=s.size();
    for(int i=s.size();i>=0;i--){
        if(s[i]=='R'){
            if((aux-i)>max){
                max=aux-i;
            }
            aux=i;
        }
    }
    if(aux+1>max){
        max=aux+1;
    }
    return max;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        cout<<minD(s)<<ENDL;
    }
    return 0;
}