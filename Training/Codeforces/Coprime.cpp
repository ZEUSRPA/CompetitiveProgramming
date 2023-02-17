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
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n;
        unordered_map<int,int> aux;
        FOR(i,0,n){
            cin>>x;
            aux[x]=i+1;
        }
        int res=0;
        for(auto y:aux){
            for(auto z:aux){
                if(__gcd(y.first,z.first)==1){
                    res=max(res,y.second+z.second);
                }
            }
        }
        cout<<(res==0?-1:res)<<ENDL;
    }
    return 0;
}