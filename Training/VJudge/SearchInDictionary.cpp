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
    int cont;

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

void search(string s, int pos, int n,vector<string> &words,string &current){
    if(pos>=s.size()){
        if(trie[n].end && pos>s.size()){
            words.pb(current);
        }
        FOR(i,0,26){
            if(trie[n].letters[i]!=-1){
                current+=i+'a';
                search(s,pos+1,trie[n].letters[i],words,current);
                current.pop_back();
            }
        }
    }else{
        if(trie[n].letters[s[pos]-'a']!=-1){
            current+=s[pos];
            search(s,pos+1,trie[n].letters[s[pos]-'a'],words,current);
            current.pop_back();
        }
    }
}

int main()
{
    IO;
    int n,k;
    cin>>n;
    string s;
    trie.pb(Node());
    FOR(i,0,n){
        cin>>s;
        add(s,0,0);
    }
    cin>>k;
    FOR(i,1,k+1){
        cin>>s;
        cout<<"Case #"<<i<<":"<<ENDL;
        vector<string> words;
        string current="";
        search(s,0,0,words,current);
        if(words.size()==0){
            cout<<"No match."<<ENDL;
        }else{
            for(auto x:words){
                cout<<x<<ENDL;
            }
        }
    }

    return 0;
}