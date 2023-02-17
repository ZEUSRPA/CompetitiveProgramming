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

lli modExp(lli x, lli n, lli mod){
    lli res=1;
    while(n){
        if(n%2==1){
            res*=x;
            res%=mod;
        }
        x=(x*x)%mod;
        n/=2;
    }
    return res;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin>>k;
    lli mod=1e9+7;
    lli res=6*modExp(4,modExp(2,k,LLONG_MAX)-2,mod);
    res%=mod;
    cout<<res<<ENDL;
    return 0;
}