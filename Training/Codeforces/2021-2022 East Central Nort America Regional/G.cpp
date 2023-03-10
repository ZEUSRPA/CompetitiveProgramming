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

struct Node{
	vector<int> letters;
	bool end;
	Node(){
		end=false;
		letters = vector<int>(26,-1);
	}
};

vector<Node> trie;

void insertT(int node,string s, int pos){
	if(pos==s.size()){
		trie[node].end=true;
		return;
	}
	if(trie[node].letters[s[pos]-'A']==-1){
		trie[node].letters[s[pos]-'A']=trie.size();
		trie.pb(Node());
	}
	insertT(trie[node].letters[s[pos]-'A'],s,pos+1);
}
int const MAXN = 51;
int const MAXR= 3000;




int main() {_ 
	
    return 0;
}
