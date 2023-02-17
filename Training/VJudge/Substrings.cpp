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

struct Node{
    int lazy;
    int value;
    Node(){
        lazy=0;
        value=0;
    }
};

Node lazyst[2*MAXN];

void update(int node,int s, int e, int l, int r,int val){
    if(lazyst[node].lazy!=0){
        if(s!=e){
            lazyst[node*2].lazy=max(lazyst[node].lazy,lazyst[node*2].lazy);
            lazyst[node*2+1].lazy=max(lazyst[node].lazy,lazyst[node*2+1].lazy);
            
        }else{
            lazyst[node].value=max(lazyst[node].value,lazyst[node].lazy);
        }
            lazyst[node].lazy=0;
    }
    if(l<=s && e<=r){
        // lazyst[node].lazy=max(lazyst[node].lazy,val);
        if(s!=e){
            lazyst[node*2].lazy=max(lazyst[node*2].lazy,val);
            lazyst[node*2+1].lazy=max(lazyst[node*2+1].lazy,val);
        }else{
            lazyst[node].value=max(lazyst[node].value,val);
        }
        return;
    }
    if(s>r || e<l){
        return;
    }
    int mid = s+(e-s)/2;
    update(node*2,s,mid,l,r,val);
    update(node*2+1,mid+1,e,l,r,val);
    
}

int query(int node, int s, int e, int dx){
    if(lazyst[node].lazy!=0){
        if(s!=e){
            lazyst[node*2].lazy=max(lazyst[node].lazy,lazyst[node*2].lazy);
            lazyst[node*2+1].lazy=max(lazyst[node].lazy,lazyst[node*2+1].lazy);
            
        }else{
            lazyst[node].value=max(lazyst[node].value,lazyst[node].lazy);
        }
        lazyst[node].lazy=0;
    }
    if(s==e){
        return lazyst[node].value;
    }
    int mid=s+(e-s)/2;
    if(dx<=mid){
        return query(node*2,s,mid,dx);
    }
    return query(node*2+1,mid+1,e,dx);
    
}


lli dp[MAXN];
lli queries[MAXN];

lli fillAns(lli node,lli tam){
    if(dp[node]!=-1){
        return dp[node];
    }
    lli ans=0;
    for(auto x:st[node].next){
        auto res = fillAns(x.second,tam);
        ans+=res;
        // queries[s+1]=max(queries[s+1],res);
    }
    if(terminal[node]){
        ans++;
        
    }

    dp[node]=ans;
    if(node!=0){
        // deb(ans);
        update(1,1,tam,st[st[node].link].len+1,st[node].len,ans);
    }
    // queries[s]=max(queries[s],dp[node]);
    return dp[node];
}

int main() {_ 
    string s;
    cin>>s;
    memset(terminal,false, sizeof(terminal));
    memset(dp,-1,sizeof(dp));
    memset(queries,0,sizeof(queries));
    sa_init();
    for(auto x:s){
        sa_extend(x);
    }
    lli current = last;
    while(current!=0){
        terminal[current]=true;
        current=st[current].link;
    }
    fillAns(0,s.size()+1);
    // getAns(0,0);
    fore(i,1,s.size()+1){
        cout<<query(1,1,s.size()+1,i)<<ENDL;
    }
    return 0;
}