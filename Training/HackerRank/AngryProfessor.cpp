#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int n,k,aux;
    while(t--){
        cin>>n>>k;
        while(n--){
            cin>>aux;
            if(aux<=0){
                k--;
            }
        }
        cout<<(k<=0?"NO":"YES")<<ENDL;
    }
    return 0;
}