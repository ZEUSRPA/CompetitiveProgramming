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

int getmin(vector<int> &hs,int current){
    if(dp.count(current)){
        return dp[current];
    }
    if(current==hs.size()-1){
        return 0;
    }
    int cost=INT_MAX;
    if(current+1<hs.size()){
        cost=min(getmin(hs,current+1)+abs(hs[current]-hs[current+1]),cost);
    }
    if(current+2<hs.size()){
        cost=min(getmin(hs,current+2)+abs(hs[current]-hs[current+2]),cost);
    }
    dp[current]=cost;
    return dp[current];

}

int main()
{
    IO;
    int n;
    cin>>n;
    vector<int> hs(n);
    for(auto &x:hs){
        cin>>x;
    }
    cout<<getmin(hs,0);
    return 0;
}