#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n,q,a;
    cin>>n;
    vector<lli> nums(n);
    vector<lli> aux(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    aux[0]=nums[0];
    for(int i=1;i<n;i++){
        aux[i]=aux[i-1]+nums[i];
    }
    cin>>q;
    while(q--){
        cin>>a;
        auto lb=lower_bound(nums.begin(),nums.end(),a);
        lb=lb;
        int a=distance(lb,nums.end())+1;
        if(a<=nums.size()){
            cout<<aux[aux.size()-a]<<ENDL;
        }else{
            cout<<0<<ENDL;
        }
        

    }
    return 0;
}