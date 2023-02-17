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

unordered_map<string,string> parent;
unordered_map<string,int> ranking;
int maximo;

string find(string a){
    if(parent[a]==a){
        return a;
    }
    parent[a]=find(parent[a]);
    return parent[a];
}

void unir(string a, string b){
    string pa=find(a);
    string ppb=find(b);
    if(pa==ppb)return;

    parent[pa]=ppb;
    ranking[ppb]+=ranking[pa];
    maximo=max(maximo,ranking[ppb]);
}

int main()
{
    IO;
    int c,r;
    string aux,a,b;
    while(cin>>c>>r){
        if(c==0&&r==0){
            break;
        }
        maximo=1;
        parent.clear();
        ranking.clear();
        FOR(i,0,c){
            cin>>aux;
            parent[aux]=aux;
            ranking[aux]=1;
        }
        FOR(i,0,r){
            cin>>a>>b;
            unir(a,b);
        }
        cout<<maximo<<ENDL;

    }
    return 0;
}