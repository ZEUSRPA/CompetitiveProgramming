#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

lli minCh(string &s,lli k){
    lli aux=0;
    for(int i=0;i<s.size()-k-1;i++){
        if(s[i]!=s[i+k]){
            aux++;
            s[i+k]=s[i];
        }
    }
    lli l=0,r=s.size()-1;
    while(l<=r){
        if(s[l]!=s[r]){
            aux++;
        }
        l++;
        r--;
    }
    return aux;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t,n,k;
    cin>>t;
    string s;
    while(t--){
        cin>>n>>k;
        cin>>s;
        cout<<minCh(s,k)<<ENDL;
    }
    return 0;
}