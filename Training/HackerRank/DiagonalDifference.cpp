#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    lli aux=0,aux2=0;
    cin>>n;
    vector<vector<int>> matrix(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    for(int i=0;i<n;i++){
        aux+=matrix[i][i];
    }

    for(int i=0,j=n-1;i<n;i++,j--){
        aux2+=matrix[i][j];
    }
    cout<<abs(aux-aux2)<<ENDL;
    return 0;
}