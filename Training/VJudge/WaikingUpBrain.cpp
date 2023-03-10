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

unordered_map<char,unordered_map<char,int>> g;
unordered_map<char,int> cont;

int getAns(string start){
	queue<char> nex;
	for(auto x:start){
		nex.push(x);
		cont[x]=0;
	}
	int time = 0;
	while(nex.size()){
		auto c=nex.size();
		while(c--){
			auto current=nex.front();
			nex.pop();
			for(auto x:g[current]){
				cont[x.first]--;
				if(cont[x.first]==0){
					nex.push(x.first);
				}
			}
		}
		time++;
	}
	for(auto x:cont){
		if(x.second>0)return -1;
	}
	return time-1;
}

int main() {_ 
	int n,m;
	string s,c;
	while(cin>>n>>m){
		cin>>s;
		g.clear();
		cont.clear();
		fore(i,0,m){
			cin>>c;
			g[c[0]][c[1]]++;
			g[c[1]][c[0]]++;
			cont[c[0]]=3;
			cont[c[1]]=3;
		}
		
	}
	int ans = getAns(s);
	if(ans==-1){
		cout<<"THIS BRAIN NEVER WAKES UP"<<ENDL;
	}else{
		cout<<"WAKE UP IN, "<<ans<<", YEARS"<<ENDL;
	}
    return 0;
}
