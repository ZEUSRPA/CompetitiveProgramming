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

void criba(vector<int>& primes){
    int maximo=1e5;
    vector<bool> lista(maximo+1,true);
    for(int i=2;i*i<=maximo;++i){
        if(lista[i]){
            for(int j=i*i;j<=maximo;j+=i){
                lista[j]=false;
            }
        }
    }
    for(int i=2;i<=maximo;++i){
        if(lista[i]){
            primes.push_back(i);
        }
    }
}

int getDivisors(int a,int b,vector<int>& primes){
    a-=b;
    set<int> divisors;
    int i=0;
    while(a!=1&&i<primes.size()){
        while(a%primes[i]==0){
            int aux=divisors.size();
            for(auto x:divisors){
                if(aux==0){
                    break;
                }
                divisors.insert(x*primes[i]);
                aux--;
            }
            divisors.insert(primes[i]);
            a/=primes[i];
        }
        i++;
    }
    if(a!=1){
        divisors.insert(a);
    }
    int cont=0;
    for(auto x:divisors){
        if(x>b){
            cont++;
        }
    }
    return cont;
}

int main(){
    IO;
    vector<int> primes;
    criba(primes);
    int a,b;
    cin>>a>>b;
    if(a==b){
        cout<<"infinity"<<ENDL;
    }else{
        int ans=0;
        if(a>b){
            ans=getDivisors(a,b,primes);
        }
        cout<<ans<<ENDL;
    }
    return 0;
}