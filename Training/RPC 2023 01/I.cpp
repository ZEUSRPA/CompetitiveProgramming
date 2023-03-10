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

int getAns(string s){
	queue<int> nex;
	
	fore(i,0,s.size()){
		if(s[i]=='1'){
			nex.push(i);
		}
	}
	int lvl=0;
	while(nex.size()){
		int c=nex.size();
		while(c--){
			int current=nex.front();
			nex.pop();
			if(current>0){
				if(s[current-1]=='0'){
					s[current-1]='1';
					nex.push(current-1);
				}
			}
			if(current<s.size()-1){
				if(s[current+1]=='0'){
					s[current+1]='1';
					nex.push(current+1);
				}
			}
		}
		lvl++;
	}
	return lvl-1;
	
}



int main() {_ 
	string s;
	cin>>s;
	cout<<getAns(s)<<ENDL;
    return 0;
}
