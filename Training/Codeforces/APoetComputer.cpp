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

struct Node{
    unordered_map<char, int> letters;
    bool end;
    int cont;
    Node(){
        end=false;
        cont=0;
    }
};

vector<Node> trie;

void insert(int node, string s, int p){
    trie[node].cont++;
    if(p<0){
        trie[node].end=true;
        return ;
    }
    if(trie[node].letters.count(s[p])==0){
        trie[node].letters[s[p]]=trie.size();
        trie.pb(Node());
    }
    insert(trie[node].letters[s[p]],s,p-1);
}

lli ans;
lli words;

void getAns(int node,lli tot){
    if(trie[node].cont>=3){
        if(tot>ans){
            ans=tot;
            words=trie[node].cont;
        }
    }else{
        return;
    }
    for(auto x:trie[node].letters){
        getAns(x.second,tot+1);
    }
}

int main() {_ 
    int t,k;
    cin>>t;
    int c=1;
    string s;
    while(t--){
        trie.clear();
        trie.pb(Node());
        cin>>k;
        fore(i,0,k){
            cin>>s;
            insert(0,s,sz(s)-1);
        }
        ans=0;
        words=k;
        getAns(0,0);
        cout<<"Case "<<c++<<":"<<ENDL;
        cout<<ans<<" "<<words<<ENDL;
    }
    return 0;
}