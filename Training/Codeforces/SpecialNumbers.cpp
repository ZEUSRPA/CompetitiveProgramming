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

lli getAns(lli n, lli k){
    lli mod=1e9+7;
    lli i=0;
    lli res=0;
    while(k){
        if(k&1){
            res+=modExp(n,i,mod);
            res%=mod;
        }
        k/=2;
        i++;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    lli n,k;
    while(t--){
        cin>>n>>k;
        cout<<getAns(n,k)<<ENDL;
    }
    return 0;
}

