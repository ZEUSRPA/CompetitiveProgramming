#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n,q,aux;
    cin>>n;
    vector<lli> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>q;
    sort(nums.begin(),nums.end());
    while(q--){
        cin>>aux;
        auto lb=lower_bound(nums.begin(),nums.end(),aux);
        auto ub=upper_bound(nums.begin(),nums.end(),aux);
        cout<<(binary_search(nums.begin(),nums.end(),aux)?"YES":"NO")<<" "<<(lb!=nums.end()?*lb:-1)<<" "<<(ub!=nums.end()?*ub:-1)<<ENDL;
    }
    return 0;
}