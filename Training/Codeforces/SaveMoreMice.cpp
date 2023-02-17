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
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> mice(k);
        for(int i=0;i<k;++i){
            cin>>mice[i];
        }
        sort(mice.rbegin(),mice.rend());
        int aux=0;
        int i=0;
        int res=0;
        while(aux+(n-mice[i])<n){
            res++;
            aux+=(n-mice[i]);
            i++;
        }
        cout<<res<<ENDL;

    }
    return 0;
}