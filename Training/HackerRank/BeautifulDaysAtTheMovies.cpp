#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i,j,k,cont=0;
    cin>>i>>j>>k;
    for(i;i<=j;i++){
        auto s=to_string(i);
        reverse(s.begin(),s.end());
        if(abs(i-stoi(s))%k==0){
            cont++;
        }
    }
    cout<<cont<<ENDL;
    return 0;
}