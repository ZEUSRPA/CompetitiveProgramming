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
#define sz(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;

int main() {_ 
	int n,m,x,dir;
	string s;
	while(cin>>n>>m>>x){
		if(n==0)break;
		vector<string> g(n);
		vector<pair<int,int>> steps={{-1,0},{0,1},{1,0},{0,-1}};
		pair<int,int> pos;
		fore(i,0,n){
			cin>>g[i];
			fore(j,0,m){
				if(g[i][j]=='N'){
					dir = 0;
					pos={i,j};
				}else if(g[i][j]=='S'){
					dir = 2;
					pos={i,j};
				}else if(g[i][j]=='L'){
					dir=1;
					pos={i,j};
				}else if(g[i][j]=='O'){
					dir=3;
					pos={i,j};
				}
			}
		}
		cin>>s;
		int ans=0;
		for(auto x:s){
			if(x=='D'){
				dir++;
				dir%=4;
			}else if(x=='E'){
				dir--;
				if(dir<0){
					dir+=4;
				}
			}else{
				int a=pos.first+steps[dir].first;
				int b=pos.second+steps[dir].second;
				if(a>=0 && a<g.size()&&b>=0&&b<g[0].size()&&g[a][b]!='#'){
					pos={a,b};
					if(g[a][b]=='*'){
						ans++;
						g[a][b]='.';
					}
				}
			}
		}
		cout<<ans<<ENDL;
	
	}
	
    return 0;
}
