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

struct state {int len,link;map<char,int> next;}; //clear next!!
state st[1000005];
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

int main() {_ 
    string a,b;
    cin>>a>>b;
    sa_init();
    if(a.size()<b.size()){
        swap(a,b);
    }
    for(auto x:a){
        sa_extend(x);
    }
    int l=0;
    int r=0;    
    int ans=0;
    int node=0;
    while(l<b.size()&&r<b.size()){
        if(l>r){
            r=l;
        }
        if(st[node].next.count(b[r])){
            node=st[node].next[b[r]];
            r++;
            ans=max(ans,r-l);
        }else{
            l++;
            if(r-l>0){
                if(st[st[node].link].len==r-l){
                    node=st[node].link;
                }
            }else{
                node=0;
            }
        }
    }
    cout<<ans<<ENDL;

    return 0;
}