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
vector<bool> num;
void criba(){
    
    FOR(i,2,5e4){
        if(num[i]){
            for(int j=i*i;j<5e4;j+=i){
                num[j]=false;
            }
        }
    }
    FOR(i,2,5e4){
        if(num[i]){
            primes.pb(i);
        }
    }
    num.clear();
}

unordered_map<int,int> factors;

int factFactorize ( int n, int prime ) {
    if(factors.count(prime)){
        return factors[prime]--;
    }
    int x = n;
    int freq = 0;


    while ( x / prime ) {
        freq += x / prime;
        x = x / prime;
    }
    factors[prime]=freq;
    return factors[prime]--;
}

int gc(int x,int y){
    int i=0;
    int res=1;
    while(y!=1 && i<primes.size()){
        while(y%primes[i]==0){
            if(factFactorize(x,primes[i])>0){
                res*=primes[i];
            }
            y/=primes[i];
        }
        i++;
    }
    if(y!=1){
        if(factFactorize(x,y)>0){
            res*=y;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    num=vector<bool>(5e4+1,true);
    
    criba();
    // int t,x,y;
    // cin>>t;
    // while(t--){
    //     cin>>x>>y;
    //     cout<<gc(x,y)<<ENDL;
    // }
    cout<<0;
    return 0;
}