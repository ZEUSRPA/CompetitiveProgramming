// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define F first
#define S second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define ALL(s) begin(s), end(s)
#define ALLR(s) rbegin(s), rend(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;


int main() {_ 
    lli t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<lli> nums(n);
        lli ans=0;
        lli mini=INT_MAX;
        lli neg=0;
        fore(i,0,n){
            cin>>nums[i];
            if(nums[i]<0){
                neg++;
            }
            nums[i]=abs(nums[i]);
            ans+=nums[i];
            mini=min(mini,nums[i]);
        }
        if(neg%2){
            ans-=(2*mini);
        }
        
        cout<<ans<<ENDL;

    }
    return 0;
}