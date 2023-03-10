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

vi st;
vi nums;

void build(int node, int s, int e){
	if(s==e){
		st[node]=nums[s];
		return;
	}
	int mid=s+(e-s)/2;
	build(node*2,s,mid);
	build(node*2+1,mid+1,e);
	st[node]=st[node*2]+st[node*2+1];
	
}

lli query(int node, int s, int e, int l, int r){
	if(l<=s && e<=r){
		return st[node];
	}
	if(s>r || e<l){
		return 0;
	}
	int mid=s+(e-s)/2;
	return query(node*2,s,mid,l,r)+query(node*2+1,mid+1,e,l,r);
}

void update(int node, int s, int e, int dx, int val){
	if(s==e){
		st[node]=val;
		return;
	}
	int mid=s+(e-s)/2;
	if(dx<=mid){
		update(node*2,s,mid,dx,val);
	}else{
		update(node*2+1,mid+1,e,dx,val);
	}
	st[node]=st[node*2]+st[node*2+1];
}

int main() {_ 
    lli n,m,a,x,b;
    cin>>n>>m;
    nums = vi(n);
    st = vi(4*n+10);
    fore(i,0,n){
    	cin>>nums[i];
    }
    build(1,0,n-1);
    fore(i,0,m){
    	cin>>x>>a>>b;
    	if(x==1){
    		update(1,0,n-1,a,b);
    	}else{
    		cout<<query(1,0,n-1,a,b-1)<<ENDL;
    	}
    }
    return 0;
}
