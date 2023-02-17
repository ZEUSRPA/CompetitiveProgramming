#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ld long double
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;

struct Node{
    vector<int> letters;
    bool end;
    lli cont;

    Node(){
        letters=vector<int>(26,-1);
        end=false;
        cont=0;
    }
};

vector<Node> trie;

void add(string s,int pos, int n){
    trie[n].cont++;
    if(s.size()==pos){
        trie[n].end=true;
        return;
    }
    if(trie[n].letters[s[pos]-'a']==-1){
        trie[n].letters[s[pos]-'a']=trie.size();
        trie.pb(Node());
    }
    add(s,pos+1,trie[n].letters[s[pos]-'a']);
}

lli getCount(string s,int pos, int n){
    if(s.size()==pos){
        return trie[n].cont;
    }
    if(trie[n].letters[s[pos]-'a']!=-1){
        return getCount(s,pos+1,trie[n].letters[s[pos]-'a']);
    }
    return 0;
}


int main()
{
    IO;
    int n,q;
    cin>>n>>q;
    string s;
    trie.pb(Node());
    FOR(i,0,n){
        cin>>s;
        add(s,0,0);
    }

    FOR(i,0,q){
        cin>>s;
        cout<<getCount(s,0,0)<<ENDL;
    }

    return 0;
}
