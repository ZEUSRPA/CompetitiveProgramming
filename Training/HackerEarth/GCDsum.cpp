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
vector<lli> arreglo;
vector<lli> current;
vector<bool> crib;
vector<lli> primes;


void criba(){
    for(int i=2;i*i<=crib.size();++i){
        if(crib[i]){
            primes.pb(i);
            for(int j=i+i;j<=crib.size();j+=i){
                crib[j]=false;
            }
        }
    }
}

void update(lli x, lli delta){
    for(;x<=arreglo.size();x+=x&(-x)){
        arreglo[x]+=delta;
        arreglo[x]%=1000000007;
    }
}

int Gcd_sum(lli x,lli delta){
    lli sum =0;
    for(lli i=1;i<=x;++i){
        sum+=__gcd(i,delta);
        sum%=1000000007;
    }
    int ax=current[x];
    current[x]=sum;
    sum=current[x]-ax;
    return sum;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n;
    crib = vector<bool> (1001,true);
    criba();
    cin>>n;
    arreglo = vector<lli> (n+1,0);
    current = vector<lli> (n+1,0);
    int g;
    for(lli i=1;i<=n;++i){
        cin>>g;
        g=Gcd(i,g);
        update(i,g);
    }
    lli q,x,y;
    char aux;
    while(q--){
        cin>>aux>>x>>y;
        if(aux=='C'){

        }else{

        }
    }

    return 0;
}

