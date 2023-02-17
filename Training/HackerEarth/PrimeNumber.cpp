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

lli modularExp(unsigned lli x,unsigned lli n,unsigned lli m){
    unsigned lli result=1;
    unsigned lli aux=1e9+7;
    x%=aux;
    while(n>0){
        if(n&1){
            result = (result*x)%aux;
        }
        x=(x*x)%aux;
        n>>=1;
    }
    result+=aux;
    result%=m;
    return result;
}

bool isPrime(unsigned lli n){
    if(n<=1 || n==4){
        return false;
    }
    if(n<=3){
        return true;
    }
    unsigned lli k=100;
    unsigned lli x;
    for(int i=0;i<k;++i){
        x=2+rand()%(n-4);
        if(__gcd(x,n)!=1){
            return false;
        }
        if(modularExp(x,n-1,n)!=1){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unsigned lli t,n;
    cin>>t;
    while(t--){
        cin>>n;
        deb(n);
        cout<<(isPrime(n)?"prime":"composite")<<ENDL;

    }
    return 0;
}

