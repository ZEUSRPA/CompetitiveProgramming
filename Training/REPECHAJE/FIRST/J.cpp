#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    unordered_map<int,int> sticks;
    int aux;
    while(n--){
        cin>>aux;
        sticks[aux]++;
    }
    aux=0;
    for(auto x:sticks){
        aux+=x.second/2;
    }
    cout<<aux/2<<ENDL;

    return 0;
}