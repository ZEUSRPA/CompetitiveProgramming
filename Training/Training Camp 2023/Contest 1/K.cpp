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

vector<vector<lli>> dp;
lli getAns(vector<lli> &satisfaction, unordered_map<lli,unordered_map<lli,lli>> &rules, lli k){
    FOR(mask,0,(1<<(satisfaction.size()+1))){
        FOR(j,0,satisfaction.size()){
            if((mask&(1<<j))){
                FOR(i,0,satisfaction.size()){
                    if((mask&(1<<i)) == 0){
                        dp[(mask|(1<<i))][i] = max(dp[(mask|(1<<i))][i],dp[mask][j]+satisfaction[i]+rules[j][i]);
                        // deb(dp[(mask|(1<<i))][i]);
                    }
                }

            }
        }
    }
    lli ans = 0 ;
    FOR(mask,0,(1<<(satisfaction.size()+1))){
        if(__builtin_popcount(mask)==k){
            // deb(mask);
            FOR(i,0,satisfaction.size()){
                // deb(dp[mask][i]);
                ans = max(ans,dp[mask][i]);
            }
        }
    }
    return ans;
}

int main()
{
    IO;
    lli n,m,k,a,b,c;
    cin>>n>>m>>k;
    dp = vector<vector<lli>> ((1<<(n+1)),vector<lli>(n+5,0));
    vector<lli> satisfaction(n);
    FOR(i,0,n){
        cin>>satisfaction[i];
        int mask = (1<<i);
        dp[mask][i]=satisfaction[i];
    }
    unordered_map<lli,unordered_map<lli,lli>> rules;
    FOR(i,0,k){
        cin>>a>>b>>c;
        a--;
        b--;
        rules[a][b]=c;
    }

    cout<<getAns(satisfaction,rules,m)<<ENDL;

    return 0;
}