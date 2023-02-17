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
    unordered_map<char,int> childs;
    int cont;
    bool end;
    Node(){
        cont=0;
        end=false;
    }
};

vector<Node> trie;
unordered_map<string,int> words;

void insertTrie(int node,string &s, int c){
    trie[node].cont++;
    if(s.size()==c){
        trie[node].end=true;
        return;
    }
    if(trie[node].childs.count(s[c])==0){
        trie[node].childs[s[c]]=trie.size();
        trie.push_back(Node());
    }
    insertTrie(trie[node].childs[s[c]],s, ++c);
}

void readTrie(int node,string &s){
    if(trie[node].end){
        words[s]=trie[node].cont;
    }
    for(auto &x:trie[node].childs){
        s.push_back(x.F);
        readTrie(x.S,s);
        s.pop_back();
    }
}

int main()
{
    IO;
    int n,q;
    cin>>n;
    string s;
    trie.push_back(Node());
    FOR(i,0,n){
        cin>>s;
        insertTrie(0,s,0);
    }
    cin>>q;
    s.clear();
    readTrie(0,s);
    
    FOR(i,0,q){
        cin>>s;
        if(words.count(s)){
            cout<<s<<" "<<words[s]<<ENDL;
        }else{
            cout<<-1<<ENDL;
        }
    }
    return 0;
}