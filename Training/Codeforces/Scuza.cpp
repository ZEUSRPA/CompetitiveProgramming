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

unordered_map<lli,lli> dp;


int main()
{
    IO;
    lli t,n,q,x;
    cin>>t;
    while(t--){
        cin>>n>>q;
        vector<lli> steps(n+1);
        vector<lli> height(n+1);
        vector<lli> search(n+1);
        search[0]=0;
        steps[0]=0;
        height[0]=0;
        FOR(i,1,n+1){
            cin>>steps[i];
            height[i]=height[i-1]+steps[i];
            search[i]=max(search[i-1],steps[i]);
        }

        FOR(i,0,q-1){
            cin>>x;
            auto pos= upper_bound(search.begin(),search.end(),x);
            pos--;
            cout<<height[pos-search.begin()]<<" ";        
            
        }
        cin>>x;
        auto pos= upper_bound(search.begin(),search.end(),x);
        pos--;
        cout<<height[pos-search.begin()]<<ENDL;        
        
    }
    return 0;
}