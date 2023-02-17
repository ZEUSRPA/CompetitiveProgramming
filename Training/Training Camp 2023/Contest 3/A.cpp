// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define F first
#define S second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

bool possible(vector<int> &nums, int m, int k){
    int si=0;
    bool odd=true;
    fore(i,0,nums.size()){
        if(odd){
            if(nums[i]<=m){
                si++;
                odd=false;
            }
        }else{
            si++;
            odd=true;
        }
    }
    int sii=0;
    bool even=false;
    fore(i,0,nums.size()){
        if(even){
            if(nums[i]<=m){
                sii++;
                even=false;
            }
        }else{
            sii++;
            even=true;
        }
    }
    return (si>=k||sii>=k);
}

int main() {_
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    fore(i,0,n){
        cin>>nums[i];
    }
    int l=1,r=1e9;
    int ans=INT_MAX;
    while(l<=r){
        int m=l+(r-l)/2;
        if(possible(nums,m,k)){
            r=m-1;
            ans=m;
        }else{
            l=m+1;
        }
    }
    cout<<ans<<ENDL;
    return 0;
}