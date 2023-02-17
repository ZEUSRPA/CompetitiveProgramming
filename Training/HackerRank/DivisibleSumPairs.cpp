#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,cont=0;
    cin>>n>>k;
    vector<int> numbers(n);
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if((numbers[i]+numbers[j])%k==0){
                cont++;
            }
        }
    }
    cout<<cont<<ENDL;
    return 0;
}