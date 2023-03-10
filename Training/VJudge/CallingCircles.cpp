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

unordered_map<string,unordered_map<string,int>> g;
unordered_map<string,int> tin,low;
unordered_map<string,bool> visited;
int timer;
stack<string> prevc;
vector<vector<string>> components;

void getAns(string node){
	visited[node]=true;
	low[node]=tin[node]=timer++;
	prevc.push(node);
	for(auto x:g[node]){
		if(!visited[x.first]){
			getAns(x.first);
		}
		low[node]=min(low[node],low[x.first]);
	}
	if(low[node]==tin[node]){
	vector<string> cmp;
		while(true){
			string current=prevc.top();
			prevc.pop();
			cmp.pb(current);
			low[current]=visited.size();
			if(node==current){
				break;
			}
		}
		components.pb(cmp);
	}
	
}


int main() {_ 
	int n,m;
	string a,b;
	int cas=1;
	while(cin>>n>>m){
		if(n==0)break;
		g.clear();
		tin.clear();
		low.clear();
		visited.clear();
		timer=0;
		components.clear();
		fore(i,0,m){
			cin>>a>>b;
			g[a][b]++;
			visited[a]=false;
			visited[b]=false;
		}
		
		for(auto x:visited){
			if(visited[x.first]==false){
				getAns(x.first);
			}
		}
		if(cas>1){
			cout<<ENDL;
		}
		cout<<"Calling circles for data set "<<cas++<<":"<<ENDL;
		for(auto x:components){
			fore(i,0,x.size()-1){
				cout<<x[i]<<", "; 
			}
			cout<<x.back()<<ENDL;
		}
		
		
	}
    return 0;
}
