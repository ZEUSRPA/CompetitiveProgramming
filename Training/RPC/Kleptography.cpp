#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int n,m;
    string sm;
    string sn;
    cin>>n>>m;
    cin>>sn>>sm;
    int aux=sn[sn.size()-1]-'a';
    string word;
    for(int i=sm.size()-1;i>sn.size()-1;i--){
        if(sm[i]-'a'<aux){
            aux=26-aux;
            aux+=sm[i]-'a';
            
        }else{
            aux=((sm[i]-'a')-aux)%26;
        }
        word+=char(aux+'a');

    }
    reverse(word.begin(),word.end());
    word+=sn;
    cout<<word<<ENDL;
    return 0;
}