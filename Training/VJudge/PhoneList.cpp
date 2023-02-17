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
    vector<int> number;
    int cont;
    bool end;

    Node(){
        number=vector<int> (10,-1);
        end=false;
        cont=0;
    }

};

vector<Node> trie;


bool add(string s,int pos,int n){
    trie[n].cont++;
    if(trie[n].end){
        return false;
    }

    if(pos==s.size()){
        trie[n].end=true;
        return trie[n].cont==1;
    }


    if(trie[n].number[s[pos]-'0']==-1){
        trie[n].number[s[pos]-'0']=trie.size();
        trie.pb(Node());
    }
    return add(s,pos+1,trie[n].number[s[pos]-'0']);

}


int main()
{
    IO;
    int t,n;
    cin>>t;
    string s;

    while(t--){
        trie.clear();
        trie.pb(Node());
        cin>>n;
        bool si=true;
        FOR(i,0,n){
            cin>>s;
            if(si){
                if(!add(s,0,0)){
                    si=false;
                }
            }
        }
        cout<<(si?"YES":"NO")<<ENDL;
    }
    return 0;
}