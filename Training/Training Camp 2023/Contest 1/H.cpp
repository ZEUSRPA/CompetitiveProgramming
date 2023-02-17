// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define F first
#define S second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
#define deb(x) cout << #x": " << (x) << endl;

struct state {int len,link;map<char,int> next;}; //clear next!!
state st[200005];
int sz,last;
void sa_init(){
	last=st[0].len=0;sz=1;
	st[0].link=-1;
}
void sa_extend(char c){
	int k=sz++,p;
	st[k].len=st[last].len+1;
	for(p=last;p!=-1&&!st[p].next.count(c);p=st[p].link)st[p].next[c]=k;
	if(p==-1)st[k].link=0;
	else {
		int q=st[p].next[c];
		if(st[p].len+1==st[q].len)st[k].link=q;
		else {
			int w=sz++;
			st[w].len=st[p].len+1;
			st[w].next=st[q].next;st[w].link=st[q].link;
			for(;p!=-1&&st[p].next[c]==q;p=st[p].link)st[p].next[c]=w;
			st[q].link=st[k].link=w;
		}
	}
	last=k;
}

lli dp[200005];
bool terminal[200005];


lli getDp(lli node){
    if(dp[node]!=-1){
        return dp[node];
    }   
    lli ans =0;
    for(auto x:st[node].next){
        ans+=getDp(x.second);
    }
    if(terminal[node]){
        ans++;
    }
    dp[node]=ans;
    return dp[node];

}

vector<pair<int,int>> getAns(string s){
    lli pos=0;
    lli node=0;
    vector<pair<int,int>> ans;
    while(pos<s.size()){
        node = st[node].next[s[pos]];
        pos++;
        if(terminal[node]){
            ans.pb({pos,dp[node]});
        }
    }   
    return ans;
}


int main() {_
    string s;
    cin>>s;
    memset(dp,-1,sizeof(dp));
    memset(terminal,false,sizeof(terminal));
    sa_init();
    for(auto x:s){
        sa_extend(x);
    }
    auto current = last;
    while(current!=0){
        terminal[current]=true;
        current=st[current].link;
    }
    getDp(0);
    auto ans=getAns(s);
    cout<<ans.size()<<ENDL;
    for(auto x:ans){
        cout<<x.first<<" "<<x.second<<ENDL;
    }
    return 0;
}