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
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

const lli MAXN =2000005;
struct state {int len,link;map<char,int> next;}; //clear next!!
state st[MAXN];
bool terminal[MAXN];
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

lli dp[MAXN];

lli getDp(lli node){
    if(dp[node]!=-1){
        return dp[node];
    }
    lli ans=1;
    for(auto x:st[node].next){
        ans+=getDp(x.second);
    }
    dp[node]=ans;
    return dp[node];

}

void query(lli node, lli t,string& current){
    if(t==0){
        return ;
    }
    for(auto x:st[node].next){
        // deb(dp[x.second]);
        if(dp[x.second]>=t){
            current+=x.first;
            // deb(x.first);
            query(x.second,t-1,current);
            break;
        }else{
            // deb(dp[x.second]);
            t-=dp[x.second];
        }
    }
}


int main() {_ 
    string s;
    cin>>s;
    memset(terminal,false, sizeof(terminal));
    memset(dp,-1,sizeof(dp));
    sa_init();
    for(auto x:s){
        sa_extend(x);
    }
    lli current = last;
    while(current!=0){
        terminal[current]=true;
        current=st[current].link;
    }
    getDp(0);
    lli q,t;
    cin>>q;
    while(q--){
        string ans="";
        cin>>t;
        query(0,t,ans);
        cout<<ans<<ENDL;

    }
    return 0;
}