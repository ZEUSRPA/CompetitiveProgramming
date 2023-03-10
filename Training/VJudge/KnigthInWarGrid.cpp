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
typedef double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

vector<ii> steps;
ii getAns(vector<vector<int>> &g){
	queue<ii> nex;
	nex.push({0,0});
	g[0][0]=2;
	ii ans={0,0};
	while(nex.size()){
		auto current = nex.front();
		nex.pop();
		int cont=0;
		set<pair<int,int>> visited;
		visited.insert({current.first,current.second});
		for(auto x:steps){
			int a = current.first+x.first;
			int b = current.second+x.second;
			if(a>=0&&a<g.size()&&b>=0&&b<g[0].size()&&g[a][b]!=-1){
				if(g[a][b]==0){
					nex.push({a,b});
					g[a][b]=2;
				}
				if(visited.find({a,b})==visited.end()){
					cont++;
				
				}
				visited.insert({a,b});
			}
		}
		if(cont%2==1){
			ans.second++;
		}else{
			ans.first++;
		}
	}
	return ans;
}

int main() {_ 
	int t,r,c,m,n,w,x,y;
	cin>>t;
	int current=1;
	while(t--){
		cin>>r>>c>>m>>n>>w;
		vector<vector<int>> g(r,vector<int>(c,0));
		steps = {{-m,n},{-n,m},{n,m},{m,n},{m,-n},{n,-m},{-n,-m},{-m,-n}};
		
		fore(i,0,w){
			cin>>x>>y;
			g[x][y]=-1;
		}
		
		auto ans = getAns(g);
		cout<<"Case "<<current++<<": "<<ans.first<<" "<<ans.second<<ENDL;
		
	}
    return 0;
}
