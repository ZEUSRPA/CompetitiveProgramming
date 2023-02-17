#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a,b;
    cin>>a>>b;
    int aux=0;
    int i=0;
    while(aux<b.size()&&i<a.size()){
        if(a[i]==b[aux]){
            aux++;
        }
        i++;
    }
    cout<<(aux==b.size()?"Yes":"No")<<ENDL;
    return 0;
}