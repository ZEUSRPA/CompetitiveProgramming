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

vector<vector<int>> v;
unordered_map<int,unordered_map<int,int>> dp;
int getH(int a,int d){
    if(d>=v.size()){
        return 0;
    }
    if(dp.count(d)&&dp[d].count(a)){
        return dp[d][a];
    }
    int h=0;
    for(int i=0;i<3;++i){
        if(i!=a){
            h=max(h,getH(i,d+1));
        }
    }
    dp[d][a]=h+v[d][a];
    return dp[d][a];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    v=vector<vector<int>>(n,vector<int>(3));
    for(int i=0;i<n;++i)
        for(int j=0;j<3;++j)
            cin>>v[i][j];
    int h=0;
    for(int i=0;i<3;++i)
        h=max(h,getH(i,0));
    cout<<h<<ENDL;
    return 0;
}

