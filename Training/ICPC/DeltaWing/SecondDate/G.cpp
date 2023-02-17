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

vector<vector<int>> dp;

int getMax(vector<string> &grid,int r,int c){
    
    if(dp[r][c]!=-1){
        return dp[r][c];
    }
    if(grid[r][c]=='Z'){
        dp[r][c]=1;
        return dp[r][c];
    }
    vector<pair<int,int>> steps={{-1,0},{-1,-1},{-1,1},{0,-1},{0,1},{1,0},{1,-1},{1,1}};
    int res=0;
    for(auto x:steps){
        int i=r+x.first;
        int j=c+x.second;
        if(i>=0&&i<grid.size()&&j>=0&&j<grid[0].size()&&grid[i][j]-grid[r][c]==1){
            res=max(res,getMax(grid,i,j));
        }
    }
    dp[r][c]=res+1;
    return dp[r][c];
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    dp=vector<vector<int>> (n,vector<int>(m,-1));
    vector<string> grid(n);
    for(int i=0;i<n;++i){
        cin>>grid[i];
    }
    int res=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;j++){
            res=max(res,getMax(grid,i,j));
        }
    }
    cout<<res<<ENDL;

    return 0;

}

