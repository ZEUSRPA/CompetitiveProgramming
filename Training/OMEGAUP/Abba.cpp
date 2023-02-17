#include <bits/stdc++.h>
#define ENDL '\n'

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int l=0,r=s.size()-1;
    unordered_map<char,char> aux;
    int res=0;
    while(l<r){
        while(aux.count(s[l])){
            s[l]=aux[s[l]];
        }
        while(aux.count(s[r])){
            s[r]=aux[s[r]];
        }
        if(s[r]!=s[l]){
            aux[s[r]]=s[l];
            res++;
        }
        l++;
        r--;
    }
    cout<<res<<ENDL;
    return 0;
}