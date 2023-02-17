#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "ABCDEFGHIJ";
    string aux=s;
    while(true){
        next_permutation(s.begin(),s.end());
        if(aux==s){
            break;
        }
        cout<<s<<ENDL;
    }
    return 0;
}