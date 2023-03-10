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

int main() {_ 
    int n,x,prev,a,best=1,current=1;
    cin>>n>>x;
    cin>>prev;
    fore(i,1,n){
    	cin>>a;
    	if(a-prev<=x){
    		current++;
    	}else{
    		best=max(best,current);
    		current=1;
    	}
    	prev=a;
    }
    best=max(best,current);
    cout<<best<<ENDL;
    return 0;
}
