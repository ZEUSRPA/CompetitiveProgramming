#include <bits/stdc++.h>
#define ENDL '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    string s;
    cin>>t;
    while(t--){
        vector<int> aux(2,0);
        cin>>s;
        for(int i=0;i<s.size();++i){
            if(s[i]=='0'){
                aux[0]++;
            }
        }
         
    }
    return 0;
}