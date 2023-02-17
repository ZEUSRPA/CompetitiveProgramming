#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,aux;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>aux;
        if(aux>=38){
            if(aux%5>2){
                aux+=5-(aux%5);
            }
        }
        cout<<aux<<ENDL;
    }
    
    return 0;
}