#include <bits/stdc++.h>
#define ENDL '\n'
#define FOR(a,b,c) for(int i=a;i<b;i+=c)
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int cont=0,sum;
        bool si=true;
        vector<int> nums(n);
        vector<int> aux(n+1,0);
        vector<int> movs(n+1,0);
        FOR(1,n+1,1){
            cin>>nums[i];
            if(si){
                sum=nums[i]-i+aux[i];
                if(sum+movs[i]<=2){
                    cont+=sum;
                    movs[i]+=sum;
                    for(int j=i;j<=nums[i];j++){
                        aux[j]++;
                    }
                }else{
                    si=false;
                }
            }
        }
        if(si){
            cout<<cont<<ENDL;
        }else{
            cout<<"Too chaotic"<<ENDL;
        }

    }
    return 0;
}