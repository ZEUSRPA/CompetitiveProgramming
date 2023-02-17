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

unordered_map<int,int> dp;

int getMax(int n,vector<int> s){
    if(n==0){
        return 0;
    }
    if(dp.count(n)){
        return dp[n];
    }
    int cuts=-1;

    for(auto x:s){
        if(n>=x){
            int a =getMax(n-x,s);
            if(a!=-1){
                cuts=max(getMax(n-x,s)+1,cuts);
            }
        }
    }
    dp[n]=cuts;
    return dp[n];
}

int main()
{
    IO;
    int n;
    vector<int> m(3);
    cin>>n>>m[0]>>m[1]>>m[2];
    cout<<getMax(n,m)<<ENDL;
    return 0;
}