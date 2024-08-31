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
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

// Min cut: nodes with dist>=0 vs nodes with dist<0
// Matching MVC: left nodes with dist<0 + right nodes with dist>0
lli const INF=1e18;
struct Dinic{
	int nodes,src,dst;
	vector<int> dist,q,work;
	struct edge {int to,rev;lli f,cap;};
	vector<vector<edge>> g;
	Dinic(int x):nodes(x),g(x),dist(x),q(x),work(x){}
	void add_edge(int s, int t, lli cap){
		g[s].pb((edge){t,sz(g[t]),0,cap});
		g[t].pb((edge){s,sz(g[s])-1,0,0});
	}
	bool dinic_bfs(){
		fill(ALL(dist),-1);dist[src]=0;
		int qt=0;q[qt++]=src;
		for(int qh=0;qh<qt;qh++){
			int u=q[qh];
			fore(i,0,sz(g[u])){
				edge &e=g[u][i];int v=g[u][i].to;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	lli dinic_dfs(int u, lli f){
		if(u==dst)return f;
		for(int &i=work[u];i<sz(g[u]);i++){
			edge &e=g[u][i];
			if(e.cap<=e.f)continue;
			int v=e.to;
			if(dist[v]==dist[u]+1){
				lli df=dinic_dfs(v,min(f,e.cap-e.f));
				if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
			}
		}
		return 0;
	}
	lli max_flow(int _src, int _dst){
		src=_src;dst=_dst;
		lli result=0;
		while(dinic_bfs()){
			fill(ALL(work),0);
			while(lli delta=dinic_dfs(src,INF))result+=delta;
		}
		return result;
	}
};

int main() {_ 
    lli n,a;
    cin>>n;
    string s;
    Dinic dinics=Dinic(n+4);
    fore(i,0,n){
        cin>>s;
        if(s=="*"){
            cin>>a;
            a--;
            if(a==0){
                dinics.add_edge(i,n+1,INF);
            }
            dinics.add_edge(i,a,INF);
        }else{
            fore(j,0,stoi(s)){
                cin>>a;
                a--;
                if(a==0){
                    dinics.add_edge(i,n+1,1);
                }
                dinics.add_edge(i,a,1);
            }
        }
    }
    dinics.add_edge(n,0,INF);
    lli ans = dinics.max_flow(n,n+1);
    if(ans==INF){
        cout<<"*"<<ENDL;
    }else{
        cout<<ans+1<<ENDL;
    }
    return 0;
}