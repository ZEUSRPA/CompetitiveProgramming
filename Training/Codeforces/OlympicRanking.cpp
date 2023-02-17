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
    int n,g,s,b;
    cin>>n;
    pair<int,pair<int,int>> best={0,{0,0}};
    string winer;
    string name;
    while(n--){
        cin>>g>>s>>b;
        cin.ignore();
        getline(cin,name);
        pair<int,pair<int,int>> aux={g,{s,b}};
        if(aux>best){
            best=aux;
            winer=name;
        }
    }
    cout<<winer<<ENDL;
    return 0;
}