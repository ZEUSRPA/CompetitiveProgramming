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
    lli t,c,r,s;
    cin>>t;
    while(t--){
        cin>>c>>r>>s;
        lli ma=c/s;
        if(c%s>0){
            ma++;
        }
        lli mi = c - (r*(s-1));
        if(mi>0){
            if(mi%s>0){
                mi/=s;
                mi++;
            }else{
                mi/=s;
            }
        }else{
            mi=0;
        }
        cout<<ma<<" "<<mi<<ENDL;
    }
    return 0;

}

