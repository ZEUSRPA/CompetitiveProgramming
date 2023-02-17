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

vector<bool> prime(10000,true);
vector<int> primes;

void criba(){
    for(int i=2;i*i<=10000;i++){
        if(prime[i]){
            primes.pb(i);
            for(int j=i+i;j<=10000;j+=i){
                prime[j]=false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    criba();
    lli n,a,b;
    cin>>n;
    while(n--){
        unordered_set<int> aux;
        cin>>a>>b;
        for(auto x:primes){
            if(a%x==0){
                aux.insert(x);
            }
            if(b%x==0){
                aux.insert(x);
            }
            while(a%x==0){
                a/=x;
            }
            while(b%x==0){
                b/=x;
            }
            if(a==1&&b==1){
                break;
            }
        }
        if(a!=1){
            aux.insert(a);
        }
        if(b!=1){
            aux.insert(b);
        }
        cout<<aux.size()<<ENDL;
    }
    return 0;
}