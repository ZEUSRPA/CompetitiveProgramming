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
    Node(){
        bits=vector<int>(2,-1);
    }
};

vector<Node> trie; 

void insert(lli n){
    lli aux;
    lli exp=29;
    lli p=0;
    while(exp>=0){
        aux=(n>>exp)&1;
        if(trie[p].bits[aux]==-1){
            trie[p].bits[aux]=trie.size();
            trie.pb(Node());
        }
        p=trie[p].bits[aux];
        exp--;
    }
}

lli doxor(lli n){
    lli mini=0;
    lli p=0;
    lli exp=29;
    lli aux;
    while(exp>=0){
        aux = (n>>exp)&1;
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
    lli q,aux=0,x,m=0;
    trie.pb(Node());
    insert(0);
    cin>>q;
    while(q--){
        cin>>aux;
        if(aux==1){
            cin>>x;
            x^=m;
            insert(x);
        }else if(aux==2){
            cin>>x;
            m^=x;
        }else{
            lli ax=doxor(m);
            ax^=m;
            cout<<ax<<ENDL;
        }
    }
    
    return 0;
}

