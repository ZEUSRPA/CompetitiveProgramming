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
    lli t,n,q,x;
    cin>>t;
    while(t--){
        cin>>n>>q;
        vector<lli> candies(n);
        FOR(i,0,n){
            cin>>candies[i];
        }
        sort(ALLR(candies));
        FOR(i,1,n){
            candies[i]+=candies[i-1];
        }
        while(q--){
            cin>>x;
            auto pos=lower_bound(ALL(candies),x);
            if(pos==candies.end()){
                cout<<-1<<ENDL;
            }else{
                cout<<pos-candies.begin()+1<<ENDL;
            }
        }
    }
    return 0;
}