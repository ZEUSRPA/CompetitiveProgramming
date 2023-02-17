#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,aux;
    map<int,int> numbers;
    cin>>n;
    while(n--){
        cin>>aux;
        numbers[aux]++;
    }
    for(auto x:numbers){
        if(x.second==1){
            cout<<x.first<<ENDL;
            break;
        }
    }
    return 0;
}