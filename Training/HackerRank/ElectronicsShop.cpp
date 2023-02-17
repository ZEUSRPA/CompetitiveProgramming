#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int b,n,m,tot=-1;
    cin>>b>>n>>m;
    vector<int> keyboards(n);
    vector<int> mouses(m);
    for(int i=0;i<n;i++){
        cin>>keyboards[i];
    }
    for(int i=0;i<m;i++){
        cin>>mouses[i];
    }
    sort(keyboards.rbegin(),keyboards.rend());
    sort(mouses.rbegin(),mouses.rend());
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int aux=keyboards[i]+mouses[j];
            if(aux<=b){
                if(aux>tot){
                    tot=aux;
                }
                break;
            }
        }
    }
    cout<<tot<<ENDL;
    return 0;
}