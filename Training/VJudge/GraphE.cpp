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


int visitG(vector<string> &g, int x, int y, char letter){
    int ans=0;
    queue<pair<int,int>> nex;
    vector<pair<int,int>> steps={{-1,0},{0,1},{1,0},{0,-1}};
    nex.push({x,y});
    g[x][y]='.';
    while(nex.size()){
        auto current=nex.front();
        nex.pop();
        ans++;
        for(auto x:steps){
            int a=current.first+x.first;
            int b=current.second+x.second;
            if(a>=0 && a <g.size()&&b>=0&&b<g[0].size()&&g[a][b]==letter){
                g[a][b]='.';
                nex.push({a,b});
            }
        }
    }
    return ans;
}

int main() {_ 
    int n,m;
    int c=1;
    while(cin>>n>>m){
        if(n==0)break;
        vector<string> g(n);
        fore(i,0,n){
            cin>>g[i];
        }
        vector<pair<int,char>> ans;
        fore(i,0,n){
            fore(j,0,m){
                if(g[i][j]!='.'){
                    char letter=g[i][j];
                    ans.pb({visitG(g,i,j,letter),letter});
                }
            }
        }
        sort(ans.begin(),ans.end(),[](pair<int,char> a, pair<int,char> b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first>b.first;
        });
        cout<<"Problem "<<c<<":"<<ENDL;
        for(auto x:ans){
            cout<<x.second<<" "<<x.first<<ENDL;
        }

        c++;
    }
    return 0;
}