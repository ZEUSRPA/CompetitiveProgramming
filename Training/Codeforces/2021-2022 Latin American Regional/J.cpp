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


lli getPos(lli a, lli b,lli w,lli h){
	lli ans;
	if(a==0){
		ans = h-b;
	}else if(a==w){
		ans = h+w+b;
	}else if(b==0){
		ans = h+a;
	}else{
		ans=2*h+w+w-a;
	}
	return ans;
}

int main() {_ 
	lli w,h,n,a,b,c,d;
	cin>>w>>h>>n;
	vector<pair<lli,lli>> aux;
	lli color=1;
	fore(i,0,n){
		cin>>a>>b>>c>>d;
		if((a==0||b==0||a==w||b==h)&&(c==0||d==0||c==w||d==h)){
			aux.pb({getPos(a,b,w,h),color});
			aux.pb({getPos(c,d,w,h),color});
			color++;
		}
	}
	sort(ALL(aux));
	stack<int> current;
	fore(i,0,aux.size()){
		if(current.size()){
			if(current.top()==aux[i].second){
				current.pop();
			}else{
				current.push(aux[i].second);
			}
		}else{
			current.push(aux[i].second);
		}
	}
	cout<<(current.size()?'N':'Y')<<ENDL;
	
	
    return 0;
}
