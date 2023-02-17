#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,q,aux;
    
    cin>>n>>k>>q;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    while(q--){
        cin>>aux;
        aux=aux-k%n;
        if(aux<0){
            aux+=n;
        }
        cout<<nums[aux]<<ENDL;
    }
    return 0;
}