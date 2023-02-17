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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,v;
    string url;
    cin>>t;
    FOR(j,1,t+1){
        unordered_map<int,vector<string>> search;
        int m=0;
        FOR(i,0,10){
            cin>>url>>v;
            search[v].pb(url);
            if(v>m){
                m=v;
            }
        }
        cout<<"Case #"<<j<<":"<<ENDL;
        for(auto x:search[m]){
            cout<<x<<ENDL;
        }
    }
    return 0;
}