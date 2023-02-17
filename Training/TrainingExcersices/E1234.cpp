#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,aux;
    cin>>n;
    set<int> numbers;
    while(n--){
        cin>>aux;
        numbers.insert(aux);
    }
    for(auto x:numbers){ 
        cout<<x<<ENDL;
    }
    return 0;
}