#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ld long double
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;


int main()
{
    IO;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &x:nums){
        cin>>x;
    }
    vector<int> n2=nums;
    sort(n2.begin(),n2.end());
    n2.resize(distance(n2.begin(),unique(n2.begin(),n2.end())));
    vector<vector<int>> dp(nums.size()+1,vector<int>(n2.size()+1,0));
    int res=0;
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[0].size();j++){
            if(nums[i-1]==n2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                res=max(res,dp[i][j]);
            }else{
                dp[i][j]=max(dp[i-1][j],max(dp[i-1][j-1],dp[i][j-1]));
            }
        }
    }
    cout<<res<<ENDL;
    return 0;
}