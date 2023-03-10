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

int getAns(vector<vector<int>> &prefix, int x,int y){
	int local_max=0;
	int global_max = INT_MIN;
	fore(i,0,prefix[0].size()){
		local_max=max((prefix[y][i]-(x==0?0:prefix[x-1][i])),local_max+(prefix[y][i]-(x==0?0:prefix[x-1][i])));
		if(local_max>global_max){
			global_max=local_max;
		}
	}
	return global_max;
}

int main() {_ 
	int n;
	cin>>n;
	vector<vector<int>> matrix(n,vector<int>(n));
	vector<vector<int>> prefix(n,vector<int>(n));
	fore(i,0,n){
		fore(j,0,n){
			cin>>matrix[i][j];
			prefix[i][j]=matrix[i][j];
		}
	}
	fore(i,0,n){
		fore(j,1,n){
			prefix[j][i]=prefix[j-1][i]+matrix[j][i];
		}
	}
	int ans=0;
	fore(i,0,n){
		fore(j,i,n){
			ans=max(ans,getAns(prefix,i,j));
		}
	}
	cout<<ans<<ENDL;
    return 0;
}
