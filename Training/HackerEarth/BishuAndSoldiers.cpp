#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q,aux;
    cin>>n;
    vector<int> soldiers(n);
    vector<int> sum(n);
    for(int i=0;i<n;i++){
        cin>>soldiers[i];
    }
    sort(soldiers.begin(),soldiers.end());
    sum[0]=soldiers[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+soldiers[i];
    }
    cin>>q;
    while(q--){
        cin>>aux;
        auto ub=upper_bound(soldiers.begin(),soldiers.end(),aux);
        int dist=distance(soldiers.begin(),ub);
        if(dist>0){
            cout<<dist<<" "<<sum[dist-1]<<ENDL;
        }else{
            cout<<0<<" "<<0<<ENDL;
        }
    }
   
    return 0;
}