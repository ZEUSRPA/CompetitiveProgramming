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
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<lli> nums(n+1);
        FOR(i,1,n+1){
            cin>>nums[i];
        }
        FOR(i,1,k+1){
            for(int j=i+k;j<n+1;j+=k){
                if(nums[j]>nums[i]){
                    swap(nums[j],nums[i]);
                }
            }
        }

        lli res=0;
        FOR(i,1,k+1){
            res+=nums[i];
        } 
        cout<<res<<ENDL;

    }
    return 0;
}
