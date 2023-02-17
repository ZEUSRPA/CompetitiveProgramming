#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,total=0,aux;;
    cin>>n;
    vector<int> types(n);
    for(int i=0;i<n;i++){
        cin>>types[i];
    }
    for(int i=1;i<=5;i++){
        int a=count(types.begin(),types.end(),i);
        if(a>total){
            total=a;
            aux=i;
        }

    }
    cout<<aux<<ENDL;
    return 0;
}