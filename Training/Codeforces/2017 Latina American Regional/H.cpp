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

int main() {_ 
	int a,b,c,d,e,f;
	int ans=0;
	cin>>a>>b>>c>>d>>e>>f;
	if(d>a){
		ans+=d-a;
	}
	if(e>b){
		ans+=e-b;
	}
	if(f>c){
		ans+=f-c;
	}	
	cout<<ans<<ENDL;
    return 0;
}
