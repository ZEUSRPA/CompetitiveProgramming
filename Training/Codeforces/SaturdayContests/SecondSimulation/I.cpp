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


int getCount(string a, string b){
	int ans = 0;
	vector<int> as(11,0);
	vector<int> bs(11,0);
	for(auto x:a){
		as[x-'0']++;
	}
	for(auto x:b){
		bs[x-'0']++;
	}
	fore(i,0,10){
		ans+=min(as[i],bs[i]);
	}
	return ans;
}

int getAns(vector<string> nums,int s, int e){
	queue<int> nex;
	vector<bool> visited(nums.size(),false);
	visited[s]=true;
	nex.push(s);
	int lvl=0;
	while(nex.size()){
		int c=nex.size();
		while(c--){
			int current = nex.front();
			nex.pop();
			if(current==e){
				return lvl;
			}
			fore(i,1,nums.size()){
				if(!visited[i]&&getCount(nums[current],nums[i])==17){
					visited[i]=true;
					nex.push(i);
				}
			}
		}
		lvl++;
		
	}
	return -1;
}

int main() {_ 
	int t,n,s,e;
	cin>>t;
	
	while(t--){
		cin>>n>>s>>e;
		vector<string> nums(n+1);
		fore(i,1,n+1){
			cin>>nums[i];
		}
		cout<<getAns(nums,s,e)<<ENDL;
	}
    return 0;
}
