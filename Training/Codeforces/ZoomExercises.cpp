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


vector<bool> matrix;
vector<lli> primes;

void criba(){
    lli total=1e6+1;
    for(lli i=2;i<total;++i){
        if(matrix[i]){
            for(lli j=i*i;j<total;j+=i){
                matrix[j]=false;
            }
        }
    }
    for(lli i=2;i<total;++i){
        if(matrix[i]){
            primes.pb(i);
        }
    }
}

bool winning(lli n){
    lli i=0;
    lli cont=0;
    while(n!=1 && i<primes.size()){
        while(n%primes[i]==0){
            cont++;
            n/=primes[i];
        }
        if(cont>1){
            return true;
        }
        i++;
    }
    if(n!=1){
        cont++;
    }
    if(cont>1){
        return true;
    }
    return false;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    matrix=vector<bool> (1e6+1,true);
    matrix[0]=false;
    matrix[1]=false;
    criba();
    lli n,aux;
    lli res=0;
    cin>>n;
    while(n--){
        cin>>aux;
        if(!winning(aux)){
            res+=(aux*2);
        }
    }
    cout<<res<<ENDL;
    return 0;
}

