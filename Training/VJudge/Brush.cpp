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
typedef double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

const int MAXN = 1e5;

int dp[MAXN];

bool cmp(ii a,ii b ,ii c){
	a.first-=c.first;
	a.second-=c.second;
	b.first-=c.first;
	b.second-=c.second;
	if(a.second==0||b.second==0){
		return a.second==b.second;
	}
	return a.first*b.second == a.second*b.first;
}

int getAns(vector<ii> &points,int mask){
	if(dp[mask]!=-1){
		return dp[mask];
	}
	if(__builtin_popcount(mask)==points.size()){
		return 0;
	}
	int ans=100;
	fore(i,0,points.size()){
		if((mask&(1<<i))==0){
			fore(j,0,points.size()){
				int currentMask = (mask|(1<<i));
				if((currentMask&(1<<j))==0){
					currentMask|=(1<<j);
					fore(k,0,points.size()){
						if((currentMask&(1<<k))==0){
							if(cmp(points[j],points[k],points[i])){
								currentMask|=(1<<k);
							}
						}
					}
					ans = min(getAns(points,currentMask),ans);
				}
			}
			break;
		}
	}
	if(ans==100){
		ans=0;
	}
	dp[mask]=ans+1;
	return dp[mask];
	
	
}

int main() {_ 
	int t,n;
	cin>>t;
	int cas=1;
	while(t--){
		cin>>n;
		vector<ii> points(n);
		memset(dp,-1,sizeof(dp));
		fore(i,0,n){
			cin>>points[i].first>>points[i].second;
		}
		int ans = getAns(points,0);
		cout<<"Case "<<cas++<<": "<<ans<<ENDL;
		
	}
    return 0;
}
