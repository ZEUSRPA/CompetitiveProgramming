// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define F first
#define S second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define ALL(s) begin(s), end(s)
#define ALLR(s) rbegin(s), rend(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZ(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

int visited[105][105];

void visitG(vector<string> &g, int x, int y){
    vector<pair<int,int>> steps={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    queue<pair<int,int>> nex;
    nex.push({x,y});
    visited[x][y]=1;
    while(nex.size()){
        auto current = nex.front();
        nex.pop();
        for(auto x:steps){
            int a=current.first+x.first;
            int b=current.second+x.second;
            if(a>=0 && a <g.size()&&b>=0&&b<g[0].size()&&visited[a][b]==-1&&g[a][b]=='@'){
                visited[a][b]=1;
                nex.push({a,b});
            }
        }
    }
}

int main() {_ 
    int n,m;
    while(cin>>n>>m){
        if(n==0)break;
        vector<string> g(n);
        memset(visited,-1,sizeof(visited));
        fore(i,0,n){
            cin>>g[i];
        }
        int ans=0;
        fore(i,0,n){
            fore(j,0,m){
                if(g[i][j]=='@'&&visited[i][j]==-1){
                    visitG(g,i,j);
                    ans++;
                }
            }
        }
        cout<<ans<<ENDL;
    }
    return 0;
}