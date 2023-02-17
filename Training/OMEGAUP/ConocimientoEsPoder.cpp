#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
map<lli,vector<lli>> mapa;
vector<int> status;

lli glifos(lli n, int e){
    lli cont=0;
    bool band=true;
    if(status[n]==0){
        if(e>0){
            e--;
        }else{
            return 0;
        }
    }else{
        e=2;
    }
    for(auto x:mapa[n]){
        cont+=glifos(x,e);
        band=false;
    }
    if(band){
        return 1;
    }else{
        return cont;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n,a,b;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        mapa[a].push_back(b);
    }
    status.resize(n);
    for(int i=0;i<n;i++){
        cin>>status[i];
    }

    cout<<glifos(0,2)<<ENDL;

    return 0;
}