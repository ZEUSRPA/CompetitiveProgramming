#include <bits/stdc++.h>
#define ENDL '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,q;
    cin>>t;
    while(t--){
        cin>>n>>q;
        vector<long long> sugar(n);
        for(int i=0;i<n;++i){
            cin>>sugar[i];
        }
        sort(sugar.rbegin(),sugar.rend());
        for(int i=1;i<n;++i){
            sugar[i]+=sugar[i-1];
        }
        while(q--){
            long long x;
            cin>>x;
            int current=-1;
            for(int p=n;p;p/=2){
                while(current+p<sugar.size()&&sugar[current+p]<x){
                    current+=p;
                }
            }
            if(current+1<sugar.size()){
                current++;
            }
            if(sugar[current]>=x){
                cout<<current+1<<ENDL;
            }else{
                cout<<-1<<ENDL;
            }
        }
    }
    return 0;
}