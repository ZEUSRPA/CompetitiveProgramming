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


int main() {_ 
	int n,x,y;
	cin>>n;
	vector<vector<int>> matrix(n,vector<int>(n));
	vector<int> cols(n,INT_MAX);
	vector<int> rows(n,INT_MAX);
	fore(i,0,n){
		fore(j,0,n){
			cin>>matrix[i][j];
			
			if(matrix[i][j]==-1){
				x=i;
				y=j;
			}else{
				cols[j]=min(cols[j],matrix[i][j]);
				rows[i]=min(rows[i],matrix[i][j]);
			}
		}
	}
	
	int ans = rows[x]+cols[y];
	cout<<ans<<ENDL;	
	
    return 0;
}
