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

int getmin(vector<int> &hs,int current,int &k){
    if(dp.count(current)){
        return dp[current];
    }
    if(current==hs.size()-1){
        return 0;
    }
    int cost=INT_MAX;
    for(int i=1;i<=k;++i){
        if(current+i<hs.size()){
            cost=min(getmin(hs,current+i,k)+abs(hs[current]-hs[current+i]),cost);

        }
        
    }
    
    dp[current]=cost;
    return dp[current];

}

int main()
{
    IO;
    int n,k;
    cin>>n>>k;
    vector<int> hs(n);
    for(auto &x:hs){
        cin>>x;
    }
    cout<<getmin(hs,0,k);
    return 0;
}