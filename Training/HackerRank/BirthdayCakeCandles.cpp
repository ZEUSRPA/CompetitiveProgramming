#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cont=1;
    int n;
    cin>>n;
    vector<int> candles(n);
    for(int i=0;i<n;i++){
        cin>>candles[i];
    }
    sort(candles.rbegin(),candles.rend());
    for(int i=1;i<n;i++){
        if(candles[i]==candles[0]){
            cont++;
        }else{
            break;
        }
    }
    cout<<cont<<ENDL;
    
    return 0;
}