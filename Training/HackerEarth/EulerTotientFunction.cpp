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


vector<int> primes;

void criba(){
    vector<bool> aux(1e6+1,true);
    aux[0]=aux[1]=false;
    
    for(int i=2;i*i<=1e6;++i){
        if(aux[i]){
            for(int j=i*i;j<=1e6;j+=i){
                aux[j]=false;
            }
        }
    }   
    for(int i=2;i<=1e6;++i){
        if(aux[i]){
            primes.pb(i);
        }
    }
}

int totient(lli n){
    lli aux=n;
    unordered_set<int> factors;
    lli i=0;
    while(n!=1){
        while(n%primes[i]==0){
            factors.insert(primes[i]);
            n/=primes[i];
        }
        i++;
    }

    lli up=aux;
    lli down=1;

    for(auto x:factors){
        up*=(x-1);
        down*=x;
    }

    return up/down;

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    criba();
    lli n;
    cin>>n;
    cout<<totient(n)<<ENDL;
    return 0;
}

