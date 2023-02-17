#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int s,t,a,b,m,n,apples=0,oranges=0,aux;
    cin>>s>>t>>a>>b>>m>>n;
    for(int i=0;i<m;i++){
        cin>>aux;
        if((a+aux)>=s&&(a+aux)<=t){
            apples++;
        }
    }
    for(int i=0;i<n;i++){
        cin>>aux;
        if((b+aux)>=s&&(b+aux)<=t){
            oranges++;
        }
    }
    cout<<apples<<ENDL;
    cout<<oranges<<ENDL;

    return 0;
}