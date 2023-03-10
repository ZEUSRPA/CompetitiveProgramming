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

vector<ii> steps = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

void attack(vector<string> &matrix,int i, int j){
	matrix[i][j]='X';
	for(auto x:steps){
		int a=i+x.first;
		int b = j+x.second;
		if(a>=0&&a<matrix.size()&&b>=0&&b<matrix[0].size()&&matrix[a][b]=='.'){
			matrix[a][b]='X';
		}
	}
}

int getAns(vector<string> &matrix,int i,int j){
	vector<ii> king = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
	queue<ii> nex;
	nex.push({i,j});
	matrix[i][j]='Z';
	int lvl=0;
	while(nex.size()){
		int c=nex.size();
		while(c--){
			auto current=nex.front();
			nex.pop();
			for(auto x:king){
				int a=current.first+x.first;
				int b = current.second+x.second;
				if(a>=0&&a<matrix.size()&&b>=0&&b<matrix[0].size()&&matrix[a][b]!='X'){
					nex.push({a,b});
					if(matrix[a][b]=='.'){
						matrix[a][b]='X';
					}else if(matrix[a][b]=='B'){
						return lvl+1;
					}
				}
			}
		}
		lvl++;
	}
	return -1;
}

int main() {_ 
	int t,n,m,x,y;
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<string> matrix(n);
		fore(i,0,n){
			cin>>matrix[i];
			
		}
		
		fore(i,0,n){
			fore(j,0,m){
				if(matrix[i][j]=='Z'){
					attack(matrix,i,j);
				}else if(matrix[i][j]=='A'){
					x=i;
					y=j;
				}
				
			}
		}
		int ans = getAns(matrix,x,y);
		if(ans==-1){
			cout<<"King Peter, you can't go now!"<<ENDL;
		}else{
			cout<<"Minimal possible length of a trip is "<<ans<<ENDL;
		}
	}
    return 0;
}
