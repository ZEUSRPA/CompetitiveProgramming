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

vector<vector<int>> g;
vector<int> low,tin;
vector<bool> visited;
int timer;
vector<vector<int>> components;
stack<int> prevc;


void getAns(int node){
	visited[node]=true;
	tin[node]=low[node]=timer++;
	prevc.push(node);
	for(auto x:g[node]){
		if(!visited[x]){
			getAns(x);
		}
		low[node]=min(low[node],low[x]);
	}
	if(tin[node]==low[node]){
		vector<int> cmp;
		while(true){
			int current = prevc.top();
			prevc.pop();
			cmp.pb(current);
			low[current]=g.size();
			if(current==node){
				break;
			}
		}
		components.pb(cmp);
	}
}

int main() {_ 
	int n,m,a,b,c;
	while(cin>>n>>m){
		if(n==0)break;
		n++;
		g=vector<vector<int>>(n);
		low=tin=vector<int>(n,-1);
		visited=vector<bool>(n,false);
		timer=0;
		components.clear();
		
		fore(i,0,m){
			cin>>a>>b>>c;
			g[a].pb(b);
			if(c==2){
				g[b].pb(a);
			}
		}
		
		fore(i,1,n){
			if(!visited[i]){
				getAns(i);
			}
		}
		if(components.size()==1){
			cout<<1<<ENDL;
		}else{
			cout<<0<<ENDL;
		}
				
	}
    return 0;
}
