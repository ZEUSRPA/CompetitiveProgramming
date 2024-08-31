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
vector<bool> visited;
vector<int> tin,low;
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
	if(low[node]==tin[node]){
		vector<int> cmp;
		while(true){
			int current = prevc.top();
			prevc.pop();
			cmp.pb(current);
			low[current]=g.size();
			if(current==node)break;
		}
		sort(ALL(cmp));
		components.pb(cmp);
	}
}


int main() {_ 
	int t,n;
	string s;
	cin>>t;
	int cas=1;
	while(t--){
		cin>>n;
		g=vector<vector<int>>(n);
		tin=low=vector<int>(n,-1);
		visited=vector<bool>(n,false);
		timer=0;
		components.clear();
		prevc.clear();
		fore(i,0,n){
			cin>>s;
			fore(j,0,n){
				if(s[j]=='Y'){
					g[i].pb(j);
				}
			}
		}
		fore(i,0,n){
			if(!visited[i]){
				getAns(i);
			}
		}
		sort(ALL(components));
		cout<<"Case "<<cas++<<": "; 
		if(components.size()==1){
			cout<<"All the friends are true friends to each other"<<ENDL;
		}else if(components.size()==n){
			cout<<"No two true friends exist."<<ENDL;
		}else{
			cout<<"There are "<<components.size()<<" groups of true friends. ";
			fore(j,0,components.size()){
				if(j>0){
					cout<<", ";
				}
				cout<<"{";
				fore(i,0,components[j].size()	){
					if(i>0){
						cout<<",";
					}
					cout<<components[j][i];
				}
				cout<<"}";
			}
			cout<<ENDL;
		}
		
	}
    return 0;
}
