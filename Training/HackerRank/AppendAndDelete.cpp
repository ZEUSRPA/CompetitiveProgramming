#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s,t;
    int k,cont=0,lim;
    cin>>s>>t>>k;
    if(s.size()<t.size()){
        lim=s.size();
    }else{
        lim=t.size();
    }
    for(int i=0;i<lim;i++){
        if(s[i]==t[i]){
            cont++;
        }
        else{
            break;
        }
    }
    int aux=s.size()-cont+t.size()-cont;
    if(k-aux>=0&&(k-aux==0 || (k-aux)/2>=t.size() || (k-aux)%2==0 || cont==0)){
        cout<<"Yes"<<ENDL;
    }else{
        cout<<"No"<<ENDL;
    }
    return 0;
}