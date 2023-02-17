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

unordered_map<int,unordered_map<int,int>> dp;

lli getmax(vector<pair<int,int>> &items,int item,int w){
    if(item==items.size()){
        return 0;
    }
    if(dp.count(item)&&dp[item].count(w)){
        return dp[item][w];
    }
    lli answer=0;
    if(w>=items[item].first){
        answer=max(getmax(items,item+1,w-items[item].first)+items[item].second,answer);
    }
    answer=max(getmax(items,item+1,w),answer);
    dp[item][w]=answer;
    return dp[item][w];
}

int main()
{
    IO;
    int n,w;
    cin>>n>>w;
    vector<pair<int,int>> items(n);
    for(auto &x:items){
        cin>>x.first;
        cin>>x.second;
    }
    lli answer=getmax(items,0,w);
    cout<<answer<<ENDL;
    return 0;
}