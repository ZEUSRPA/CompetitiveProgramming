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

vector<vector<char>> grid;

vector<vector<lli>> dp;

lli paths(int i,int j){
    if(i==grid.size()-1&&j==grid[0].size()-1){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    lli p=0;
    lli mod=1e9+7;
    if(i+1<grid.size()){
        if(grid[i+1][j]=='.'){
            p=(p+paths(i+1,j))%mod;
        }
    }
    if(j+1<grid[0].size()){
        if(grid[i][j+1]=='.'){
            p=(p+paths(i,j+1))%mod;
        }
    }
    dp[i][j]=p;
    return dp[i][j];

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h,w;
    cin>>h>>w;
    dp=vector<vector<lli>>(h,vector<lli>(w,-1));
    grid=vector<vector<char>>(h,vector<char>(w));
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            cin>>grid[i][j];
        }
    }
    cout<<paths(0,0)<<ENDL;
    return 0;
}

