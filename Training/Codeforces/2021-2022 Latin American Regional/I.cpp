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

lli getAns(lli days, lli current){
	
	lli start = current-(days%7);
	if(start<0){
		start+=7;
	}
	lli ans = 0;
	if(start!=0){
		days-=7-start;
	}
	if(days<0){
		days+=7-start;
	}else{
		lli div=days%91;
		
	}
	
	if(days<30){
		while(days<30){
			start++;
			
		}
	}else{
		if(start!=0){
			days-=7-start;
		}
	
	}
	
	
}

int main() {_ 
	string s;
	lli n,current,a,ans=LLONG_MAX;
	cin>>s>>n;
	unordered_map<string,lli> days;
	days["Mon"]=0;
	days["Tue"]=1;
	days["Wed"]=2;
	days["Thu"]=3;
	days["Fri"]=4;
	days["Sat"]=5;
	days["Sun"]=6;
	current=days[s];
	
	fore(i,0,n){
		cin>>a;
		ans = min(getAns(a,current),ans);
	}
	
	cout<<ans<<ENDL;
    return 0;
}
