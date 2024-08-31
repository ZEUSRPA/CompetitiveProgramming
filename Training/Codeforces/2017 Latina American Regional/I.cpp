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

vector<pair<lli,lli>> g;
priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>> nex;
vector<lli> parent;

lli find(lli x){
	if(parent[x]==x){
		return x;
	}
	parent[x]=find(parent[x]);
	return parent[x];
}

lli unite(lli x, lli y){
	
}


void generateMST(){

}

int main() {_ 
	int *p = new int;
	(*p) = 5;
	int k= (*p);
	cout<<k<<endl;
    return 0;
}
