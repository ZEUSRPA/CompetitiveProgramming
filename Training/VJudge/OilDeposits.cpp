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

void dfs(vector<string> &grid,pair<int,int> pos){
    vector<pair<int,int>> steps={{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
    grid[pos.first][pos.second]='*';
    for(auto x:steps){
        int a=pos.first+x.first;
        int b=pos.second+x.second;
        if(a>=0&&a<grid.size()&&b>=0&&b<grid[0].size()&&grid[a][b]=='@'){
            dfs(grid,{a,b});
        }
    }
}

int main()
{
    IO;
    int m,n;
    while(cin>>m){
        cin>>n;
        if(m==0){
            break;
        }
        vector<string> grid(m);
        for(auto &x:grid){
            cin>>x;
        }
        int cont=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]=='@'){
                    dfs(grid,{i,j});
                    cont++;
                }
            }
        }
        cout<<cont<<ENDL;
    }
    return 0;
}