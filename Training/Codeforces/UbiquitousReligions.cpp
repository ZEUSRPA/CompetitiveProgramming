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


vector<int> parent;
int find(int a){
    if(a==parent[a]){
        return a;
    }
    parent[a]=find(parent[a]);
    return parent[a];
}

void unir(int a,int b){
    int pa=find(a);
    int ppb=find(b);
    if(pa==ppb){
        return;
    }
    parent[pa]=parent[ppb];
}

int main()
{
    IO;
    int n,m,x,y;
    int c=1;
    while(cin>>n>>m){
        if(n==0&&m==0){
            break;
        }
        parent=vector<int>(n);
        FOR(i,0,n){
            parent[i]=i;
        }

        FOR(i,0,m){
            cin>>x>>y;
            x--;
            y--;
            unir(x,y);

        }
        set<int> total;
        for(auto x:parent){
            total.insert(find(x));
        }
        cout<<"Case "<<c++<<": "<<total.size()<<ENDL;


    }
    return 0;
}