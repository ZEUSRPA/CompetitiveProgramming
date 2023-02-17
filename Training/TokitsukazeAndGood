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
    IO;
    int t,n;
    cin>>t;
    string s;
    while(t--){
        cin>>n;
        cin>>s;
        int res=0;
        int current=0;
        char curr='x';
        for(auto x:s){
            if(x!=curr){
                if(current%2){
                    current=0;
                    res++;
                }else{
                    current=1;
                }
                curr=x;
            }else{
                current++;
            }
        }
        cout<<res<<ENDL;
    }
    return 0;
}