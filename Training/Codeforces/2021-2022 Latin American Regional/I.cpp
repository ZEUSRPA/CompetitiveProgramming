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

unordered_map<string,int> days;
unordered_map<int,int> nex;

lli getAns(lli days,lli today){
	lli ans=0;
	if(days==0){
		ans+=30;
		if(today==3){
			ans+=2;
		}
		if(today==4){
			ans+=1;
		}
		return ans;
	}
	lli start = today;
	lli left = days%7;
	start-=left;
	if(start<0){
		start+=7;
	}
	bool doit=true;
	while(days>=30){
		if(start==0&&doit){
			days%=91;
			doit=false;
		}else{
			if(start==3){
				days-=2;
			}else if(start==4){
				days--;
			}
			days-=30;
			start=nex[start];
		}
	}
	if(days<=0){
		return abs(days);
	}
	ans = 30 - days;
	if(start==3){
		ans+=2;
	}else if(start==4){
		ans++;
	}
	return ans;

}

int main() {_ 
	string today;
	lli n,aux,current;
	days["Mon"] = 0;
	days["Tue"] = 1;
	days["Wed"] = 2;
	days["Thu"] = 3;
	days["Fri"] = 4;
	days["Sat"] = 5;
	days["Sun"] = 6;

	nex[0]=2;
	nex[1]=3;
	nex[2]=4;
	nex[3]=0;
	nex[4]=0;


	cin>>today>>n;
	current = days[today];
	lli best = LLONG_MAX;
	fore(i,0,n){
		cin>>aux;
		best = min(best,getAns(aux,current));
	}
	cout<<best<<ENDL;
    return 0;
}
