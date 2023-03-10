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

int main() {_ 
	string a,b,c,d;
	bool cas=false;
	while(cin>>a){
		if(a=="#"){
			break;
		}
		cin>>b>>c>>d;
		unordered_map<char,int> ap;
		unordered_map<char,int> bp;
		unordered_map<char,int> cp;
		unordered_map<char,int> dp;
		fore(i,0,a.size()){
			if(ap.count(a[i])==0){
				ap[a[i]]=i;
			}
		}
		fore(i,0,b.size()){
			if(bp.count(b[i])==0){
				
				bp[b[i]]=i;
			}
		}
		fore(i,0,c.size()){
			if(cp.count(c[i])==0){
				
				cp[c[i]]=i;
			}
		}
		fore(i,0,d.size()){
			if(dp.count(d[i])==0){
				
				dp[d[i]]=i;
			}
		}
		pair<int,int> current={INT_MAX,INT_MAX};
		fore(i,0,a.size()){
			if(bp.count(a[i])){
				current={ap[a[i]],bp[a[i]]};
				break;
			}
		}
		pair<int,int> current2={INT_MAX,INT_MAX};
		fore(i,0,c.size()){
			if(dp.count(c[i])){
				current2={cp[c[i]],dp[c[i]]};
				break;
			}
		}
		if(cas){
			cout<<ENDL;
		}else{
			cas=true;
		}
		if(current.first!=INT_MAX && current2.first!=INT_MAX){
			int x=a.size()+c.size()+3;
			int y=max(current.second,current2.second)+max(b.size()-current.second,d.size()-current2.second);
			int xpos=max(current.second,current2.second);
			
			vector<string> ans(y,string(x,' '));
			vector<int> lastp(y,0);
			x=0;
			y=xpos;
			fore(i,0,a.size()){
				lastp[y]=max(lastp[y],x);
				ans[y][x++]=a[i];
			}
			int cy=y-current.second;
			fore(i,0,b.size()){
				lastp[cy]=max(lastp[cy],current.first);
				ans[cy++][current.first]=b[i];
			}
			
			x+=3;
			fore(i,0,c.size()){
				lastp[y]=max(lastp[y],x);
				ans[y][x++]=c[i];
			}
			cy=y-current2.second;
			
			cy=y-current2.second;
			fore(i,0,d.size()){
				lastp[cy]=max(lastp[cy],int(a.size()+3+current2.first));
				ans[cy++][a.size()+3+current2.first]=d[i];
			}
			
			fore(i,0,ans.size()){
				fore(j,0,ans[i].size()){
					cout<<ans[i][j];
					if(lastp[i]==j){
						cout<<ENDL;
						break;
					}
				}
			}
			
		}else{
			cout<<"Unable to make two crosses"<<ENDL;
		}
	}
	    
    return 0;
}
