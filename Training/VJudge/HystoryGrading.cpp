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


void getAns(vector<vector<int>>& students){
	
	for(auto x:students){
		
		int ans=0;
		vector<int> dp(x.size()+5,INT_MAX);
		dp[0]=INT_MIN;
		fore(i,0,x.size()){
			int pos= upper_bound(ALL(dp),x[i])-dp.begin();
			if(dp[pos-1]<x[i] && dp[pos]>x[i]){
				dp[pos]=x[i];
				ans=max(ans,pos);
			}
			
		}
		cout<<ans<<ENDL;
	}
}


int main() {_ 
	int n;
	string s;
	unordered_map<int,int> order;
	vector<vector<int>> students;
	while(getline(cin,s)){
		vector<int> values;
		string current="";	
		for(auto x:s){
			if(x==' '){
				if(current.size()){
					values.pb(stoi(current));
				}
				current="";
			}else{
				current+=x;
			}
		}
		if(current.size()){
			values.pb(stoi(current));
		
		}
		if(values.size()==1){
			getAns(students);
			students.clear();
			n=values[0];
			order.clear();
		}else{
			if(order.size()==0){
				fore(i,0,n){
					order[i+1]=values[i];
				}
			}else{
				vector<int> auxval(n);
				fore(i,0,n){
					auxval[values[i]-1]=order[i+1];
				}
				students.pb(auxval);
			}	
		}
	}
	getAns(students);
    return 0;
}
