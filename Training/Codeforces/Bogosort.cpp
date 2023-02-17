#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,aux;
    vector<int> num;
    cin>>t;
    for(int j=0;j<t;j++){
        cin>>n;
        num.clear();
        for(int i=0;i<n;i++){
            cin>>aux;
            num.push_back(aux);
        }
        sort(num.rbegin(),num.rend());
        for(int i=0;i<n-1;i++){
            cout<<num[i]<<" ";
        }
        cout<<num[n-1]<<ENDL;
        
    }
    return 0;
}