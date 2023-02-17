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


int primes(int n){
    vector<bool> primes(n+1,true);
    primes[0]=false;
    primes[1]=false;
    int cont=0;
    for(int i=2;i*i<=n;++i){
        if(primes[i]){
            for(int j=i*i;j<=n;j+=i){
                primes[j]=false;
            }
        }
    }
    for(int i=2;i<=n;++i){
        if(primes[i]){
            cont++;
        }
    }
    return cont;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    cout<<primes(n)<<ENDL;
    return 0;
}

