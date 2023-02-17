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

set<int> primes;
vector<int> cont;

void criba(){
    vector<bool> aux(1e6+1,true);
    cont=vector<int>(1e6+1);
    aux[0]=aux[1]=false;
    for(int i=2;i*i<=1e6;++i){
        if(aux[i]){
            for(int j=i*i;j<=1e6;j+=i){
                aux[j]=false;
            }
        }
    }
    int current=0;
    int cPrimes=0;
    cont[0]=0;
    for(int i=1;i<=1e6;++i){
        if(aux[i]){
            primes.insert(i);
            cPrimes++;
        }
        if(primes.find(cPrimes)!=primes.end()){
            current++;
        }
        cont[i]=current;
    }

}

int nPrimes(int l, int r){
    return cont[r]-cont[l-1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    criba();
    int t,l,r;
    cin>>t;
    while(t--){
        cin>>l>>r;
        cout<<nPrimes(l,r)<<ENDL;
    }
    return 0;
}

