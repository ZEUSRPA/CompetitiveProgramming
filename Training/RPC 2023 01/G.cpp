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

unordered_map<lli,lli> dx;

void getFact(){
	lli current=1;
	dx[0]=1;
	fore(i,1,10){
		current*=i;
		dx[i]=current;
		//deb(dx[i]);
	}
	
}

lli getF(lli val){
	//deb(val);
	if(dx.count(val)){
		return dx[val];
	}
	lli ans = dx[val%10] + getF(val/10);
	
	dx[val]=ans;
	return dx[val];
}

lli doBinary(lli y,lli fact){
	lli l=0,r=100000000000;
	lli pos=LLONG_MAX;
	while(l<=r){
		lli mid = l+(r-l)/2;
		lli fs=mid*10LL+fact;
		lli cu=getF(fs);
		deb(fact);
		deb(fs);
		if(cu==y){
			return fs;
		}else if(cu>y){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	
	return pos;
}

lli getAns(lli y){
	lli ans=LLONG_MAX;
	fore(i,0,10){
		ans = min(doBinary(y,i),ans);
	}
	return ans;
}

int main() {_ 
	lli y;
	cin>>y;
	getFact();
	fore(i,0,9){
		fore(j,0,9){
			cout<<getF(i*10+j)<<" ";
		}
		cout<<ENDL;
	}
	cout<<getAns(y)<<ENDL;	
    return 0;
}
