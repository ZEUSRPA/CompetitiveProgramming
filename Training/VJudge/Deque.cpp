#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define mp make_pair
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



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x:a){
        cin>>x;
    }
    vector<vector<lli>> dp(n+1,vector<lli>(n+1));
    for(int l=n-1;l>=0;--l){
        for(int r=l;r<n;++r){
            if(l==r){
                dp[l][r]=a[l];
            }else{
                dp[l][r]= max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<ENDL;
    return 0;
}

