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

lli getAns(vector<vector<ii>> &g, vector<vi> &times, vector<vi> &original){
	priority_queue<ii,vector<ii>,greater<ii>> pq;
	pq.push({0,1});
	vi dist(g.size(),LLONG_MAX);
	dist[1]=0;
	while(pq.size()){
		auto current=pq.top();
		pq.pop();
		//assert(current.second>=dist.size());
		if(current.first==dist[current.second]){
			for(auto x:g[current.second]){
				lli distance=x.second;
				auto verify = lower_bound(ALL(original[current.second]),current.first);
				if(verify!=original[current.second].end() && *verify ==current.first){
					auto waiting = lower_bound(ALL(times[current.second]),current.first);
					if(waiting!=times[current.second].end()){
						distance += (*waiting)+1;
					}
				}else{
					distance+=current.first;
				}
				if(distance<dist[x.first]){
					pq.push({distance,x.first});
					dist[x.first]=distance;
				}
				
			}
		}
	}
	return dist[g.size()-1];
}

int main() {_ 
    lli n,m,a,b,c,k;
    cin>>n>>m;
    vector<vector<ii>> g(n+1);
    vector<vector<lli>> times(n+1);
    vector<vector<lli>> original(n+1);
    fore(i,0,m){
    	cin>>a>>b>>c;
    	g[a].pb({b,c});
    	g[b].pb({a,c});
    }
    fore(i,1,n+1){
    	cin>>k;
    	lli best=-1;
    	lli current=-1;
    	fore(j,0,k){
    		cin>>current;
    		original[i].pb(current);
    		if(current-best==1){
    			best=current;
    		}else{
    			times[i].pb(best);
    			best=current;
    		}
    	}
    	times[i].pb(best);
    	
    }
    lli ans = getAns(g,times,original);
    if(ans==LLONG_MAX){
    	ans=-1;
    }
    cout<<ans<<ENDL;
    
}
