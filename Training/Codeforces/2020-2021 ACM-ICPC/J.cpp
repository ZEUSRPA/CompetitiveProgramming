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


int main()
{
    IO;
    int n,aux;
    cin>>n;
    vector<vector<int>> switches(n+1);
    vector<vector<int>> lights(n+1);

    auto valid=[&](int pos)->bool{
        bool good = false;
        unordered_set<int> current;
        for(auto sw:lights[pos]){
            current.insert(sw);
        }
        

    };

    FOR(i,1,n){
        FOR(k,1,n){
            cin>>aux;
            if(aux==1){
                switches[i].pb(k);
                lights[k].pb(i);
            }
        }
    }

    return 0;
}
