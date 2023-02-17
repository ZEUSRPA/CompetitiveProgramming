#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define mp make_pair
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
    vector<int> bits;
    lli cont;
    Node(){
        bits=vector<int> (2,-1);
        cont=1;
    }
};

vector<Node> trie;

void insert(lli n){
    lli p=0;
    lli aux;
    lli exp=59;
    while(exp>=0){
        aux=(n>>exp)&1;
        if(trie[p].bits[aux]==-1){
            trie[p].bits[aux]=trie.size();
            trie.pb(Node());
        }else{
            trie[trie[p].bits[aux]].cont++;
        }
        p=trie[p].bits[aux];
        exp--;
    }
}

lli query(lli n, lli t){
    lli p=0;
    lli aux;
    lli exp=59;
    lli mini=0;
    while(exp>=0){
        aux = (n>>exp)&1;
        if(trie[trie[p].bits[aux]].cont<t){
            aux = (aux)?0:1;
        }
        if(trie[p].bits[aux]!=-1){
            mini+=aux<<exp;
            p=trie[p].bits[aux];
        }else if(trie[p].bits[1-aux]!=-1){
            mini+=(1-aux)<<exp;
            p=trie[p].bits[1-aux];
        }else{
            break;
        }
        exp--;
    }
    return mini;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    trie.pb(Node());
    lli q,aux,n,t;
    cin>>q;
    while(q--){
        cin>>aux;
        if(aux == 1){
            cin>>n;
            insert(n);
        }else{
            cin>>n>>t;
            cout<<(query(n,t)^n)<<ENDL;
        }
    }
    
    return 0;
}

