#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,d,m,cont=0,aux=0;
    cin>>n;
    vector<int> parts(n);
    for(int i=0;i<n;i++){
        cin>>parts[i];
    }
    cin>>d>>m;
    if(parts.size()>=m){
        for(int i=0;i<m;i++){
            aux+=parts[i];
        }
        if(aux==d){
            cont++;
        }
        if(parts.size()>1){
            for(int i=1;i<=parts.size()-m;i++){
                aux=aux-parts[i-1]+parts[i+m-1];
                if(aux==d){
                    cont++;
                }
            }
        }
    }
    cout<<cont<<ENDL;
    return 0;
}