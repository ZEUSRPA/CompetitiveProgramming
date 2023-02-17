#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma")
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

int const MAXN=2e6+5;

struct state {int len,link;map<char,int> next;}; //clear next!!
state st[MAXN];
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

int dp[MAXN];
int best=0;
int maxi=0;

int getAns(int node,char current){
    int mask = 0;
    if(dp[node]!=-1){
        return dp[node];
    }
    for(auto x:st[node].next){
        mask|=getAns(x.second,x.first);
    }
    if(current>='A'&&current<='Z'){
        mask=(1<<(current-'A'));
    }
    if(mask==maxi){
        best=max(best,st[node].len);
    }
    dp[node]=mask;
    return dp[node];
}

int main() {_ 
    string s;
    char special='A';
    memset(dp,-1,sizeof(dp));
    sa_init();
    while(cin>>s){
        s+=special;
        for(auto x:s){
            sa_extend(x);
        }
        special++;
    }
    char current='x';
    maxi = special - 'A';
    int aux = 0;
    int cu=1;
    while(maxi--){
        aux+=cu;
        cu<<=1;
    }
    maxi=aux;
    // deb(maxi);
    getAns(0,current);
    cout<<best<<ENDL;
    return 0;
}