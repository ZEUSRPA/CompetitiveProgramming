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

vector<vector<pair<int,int>>> g;

lli getAns(lli n){
	lli ans=0;
	while(n!=1){
		if(n%2==0){
			n/=2;
		}else{
			n--;
		}
		ans++;
	}
	return ans;
}

int main() {_ 
	lli t,n,q,aux,a,b;
	cin>>t;
	while(t--){
		cin>>n>>q;
		vector<lli> pref(n+1,0);
		fore(i,1,n+1){
			cin>>aux;
			pref[i]=getAns(aux);
			pref[i]+=pref[i-1];
			
		}
		while(q--){
			cin>>a>>b;
			cout<<pref[b]-pref[a-1]<<ENDL;
		}
	}
	
    return 0;
}
