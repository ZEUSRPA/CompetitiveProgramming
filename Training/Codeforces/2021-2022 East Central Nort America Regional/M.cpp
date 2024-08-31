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

struct Node{
	vector<int> letters;
	bool end;
	Node(){
		end=false;
		letters = vector<int>(26,-1);
	}
};

vector<Node> trie;

void insertT(int node,string s, int pos){
	if(pos==s.size()){
		trie[node].end=true;
		return;
	}
	if(trie[node].letters[s[pos]-'A']==-1){
		trie[node].letters[s[pos]-'A']=trie.size();
		trie.pb(Node());
	}
	insertT(trie[node].letters[s[pos]-'A'],s,pos+1);
}
int const MAXN = 51;
int const MAXR= 3000;

vector<vector<char>> matrix;
vector<vector<bool>> visited;
vector<pair<int,int>> steps={{0,1},{0,-1},{1,0}};
int dp[MAXN][MAXN][3][MAXR];
int getAns(int x, int y,int node,int prev){
	if(dp[x][y][prev][node]!=-1){
		return dp[x][y][prev][node];
	}
	int ans= INT_MAX;
	if(trie[node].end){
		if(x==matrix.size()-1){
			return 1;
		}
		ans=getAns(x,y,0,prev);
		if(ans!=INT_MAX){
			ans--;
		}
	}
	visited[x][y]=true;
	int cont=0;
	for(auto z:steps){
		int a=x+z.first;
		int b=y+z.second;
		if(a>=0&&a<matrix.size()&&b>=0&&b<matrix[0].size()&&!visited[a][b]&&trie[node].letters[matrix[a][b]-'A']!=-1){
			ans=min(ans,getAns(a,b,trie[node].letters[matrix[a][b]-'A'],cont));
		}
		cont++;
	}
	if(ans!=INT_MAX){
		ans++;	
	}
	visited[x][y]=false;
	dp[x][y][prev][node]=ans;
	return dp[x][y][prev][node];
}


int main() {_ 
	trie.pb(Node());
	memset(dp,-1,sizeof(dp));
	int n,m,k;
	cin>>n>>m>>k;
	matrix=vector<vector<char>> (n,vector<char>(m));
	visited = vector<vector<bool>>(n,vector<bool>(m,false));
	fore(i,0,n){
		fore(j,0,m){
			cin>>matrix[i][j];
		}
	}
	string s;
	fore(i,0,k){
		cin>>s;
		insertT(0,s,0);
	}
	int ans=INT_MAX;
	fore(i,0,m){
		if(trie[0].letters[matrix[0][i]-'A']!=-1){
			ans = min(ans,getAns(0,i,trie[0].letters[matrix[0][i]-'A'],0));
		}
	}
	if(ans==INT_MAX){
		cout<<"impossible"<<ENDL;
	}else{
		cout<<ans<<ENDL;
	}
    return 0;
}
