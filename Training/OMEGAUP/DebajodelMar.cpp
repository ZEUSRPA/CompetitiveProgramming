#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

vector<bool> criba;
vector<lli> primos;

void doCriba(lli n){
    criba=vector<bool>(n+1,true);
    if(n>=0){
        criba[0]=false;
        if(n>=1){
            criba[1]=false;
        }
    }
    for(int i=2;i<=n;i++){
        if(criba[i]){
            for(int j=i+i;j<=n;j+=i){
                criba[j]=false;
            }
            primos.push_back(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}