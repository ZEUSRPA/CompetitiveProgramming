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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,aux,g,p;
    string name;

    while(cin>>n){
        unordered_map<string,int> people;
        vector<string> names;
        FOR(i,0,n){
            cin>>name;
            people[name]=0;
            names.pb(name);
        }
        FOR(i,0,n){
            cin>>name;
            cin>>aux;
            people[name]-=aux;
            cin>>g;
            if(g>0){
                p=aux/g;
                people[name]+=aux%g;
            }else{
                p=0;
            }
            
            FOR(j,0,g){
                cin>>name;
                people[name]+=p;
            }
        }
        for(auto &x:names){
            cout<<x<<" "<<people[x]<<ENDL;
        }
        cout<<ENDL;

    }
    return 0;
}