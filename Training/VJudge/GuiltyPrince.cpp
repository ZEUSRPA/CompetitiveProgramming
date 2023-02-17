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

int bfs(vector<string> &grid,pair<int,int> pos){
    vector<pair<int,int>> steps={{-1,0},{0,-1},{1,0},{0,1}};
    queue<pair<int,int>> nex;
    nex.push(pos);
    int cont=0;
    while(nex.size()){
        auto current=nex.front();
        nex.pop();
        cont++;
        for(auto x:steps){
            int a=current.first+x.first;
            int b=current.second+x.second;
            if(a>=0&&a<grid.size()&&b>=0&&b<grid[0].size()&&grid[a][b]=='.'){
                grid[a][b]='*';
                nex.push({a,b});
            }
        }
    }
    return cont;
}


int main()
{
    IO;
    int t,w,h,a,b;
    cin>>t;
    int c=1;
    while(t--){
        cin>>w>>h;
        vector<string> grid(h);
        for(auto &x:grid){
            cin>>x;
        }
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]=='@'){
                    res=bfs(grid,{i,j});
                }
            }
        }
        cout<<"Case "<<c++<<": "<<res<<ENDL;

    }
    return 0;
}