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

vector<lli> primes;

void criba(){
    vector<bool> aux(1e4+1,true);
    aux[0]=aux[1]=false;
    for(int i=2;i<=1e4;++i){
        if(aux[i]){
            for(int j=i*i;j<=1e4;j+=i){
                aux[j]=false;
            }
        }
    }

    for(int i=2;i<=1e4;++i){
        if(aux[i]){
            primes.pb(i);
        }
    }
}

lli modularExp(lli x, lli n, lli m){
    lli res=1;

    while(n>0){
        if(n&1){
            res=(res*x)%m;
        }
        x=(x*x)%m;
        n>>=1;
    }
    
    return res;
}

unordered_map<lli,lli> input;

unordered_map<lli,lli> factors;


void getFactors(lli n){
    lli aux=n;
    int i=0;
    while(n!=1 && i<primes.size()){
        while(n%primes[i]==0){
            if(primes[i]!=aux){
                factors[primes[i]]++;
                n/=primes[i];
            }else{
                n=1;
                break;
            }
        }
        i++;
    }

    if(n!=1){
        if(n!=aux){
            factors[n]++;
        }
    }
}

lli getSum(lli m){

    lli result=0;
    for(auto x:input){
        getFactors(x.first);
        factors[x.first]+=x.second;
    }
    
    factors[1]=0;
    for(auto x:factors){
        if(x.second>1){
            result = (result+modularExp(x.first,x.second,m))%m;
        }
    }
    result++;

    return result;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    criba();
    lli n,x,y;
    lli result=1;
    lli m=1e9+7;
    cin>>n;
    while(n--){
        cin>>x>>y;
        input[x]+=y;
    }
    cout<<getSum(m)<<ENDL;

    return 0;
}

