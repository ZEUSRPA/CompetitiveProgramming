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
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int diff=n/2;
        
        vector<int> ans;
        int current=1;
        int cont=0;
        FOR(i,1,n/2+1){
            ans.pb(i+diff);
            ans.pb(i);
            cont+=2;
        }
        if(cont<n){
            cout<<n<<" ";
            n--;
        }
        
        FOR(i,0,n-1){
            cout<<ans[i]<<" ";
        }
        cout<<ans[n-1]<<ENDL;
        
    }
    return 0;
}