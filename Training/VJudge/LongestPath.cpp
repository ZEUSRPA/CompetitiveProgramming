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

vector<vector<int>> graph;
vector<int> dp;



int longest(int n){
    if(dp[n]!=-1){
        return dp[n];
    }
    int m=0;
    for(auto x:graph[n]){
        m=max(m,longest(x));
    }
    dp[n]=m+1;
    return dp[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,x,y;
    
    cin>>n>>m;
    dp=vector<int>(n+1,-1);
    graph=vector<vector<int>>(n+1);
    for(int i=0;i<m;++i){
        cin>>x>>y;
        graph[x].push_back(y);
    }
    int maxi=0;
    for(int i=1;i<=n;++i){
        maxi=max(longest(i),maxi);
    }
    cout<<maxi-1<<ENDL;

    return 0;
}

