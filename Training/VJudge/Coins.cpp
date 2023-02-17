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
    double p;
    cin>>n;
    vector<double> dp(n+1,0);
    dp[0]=1;
    for(int i=0;i<n;++i){
        cin>>p;
        for(int j=i+1;j>=0;--j){
            dp[j] = (j==0?0:dp[j-1] * p) + dp[j] * (1-p);
        }
    }

    double ans=0;
    for(int i=0; i<=n;++i){
        if(i>n-i){
            ans+=dp[i];
        }
    }

    cout<<fixed<<setprecision(10)<<ans<<ENDL;

    return 0;
}

