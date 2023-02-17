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
    vector<bool> aux(1e6+1,true);
    aux[0]=aux[1]=false;
    
    for(lli i=2;i*i<=1e6;++i){
        if(aux[i]){
            for(lli j=i*i;j<=1e6;j+=i){
                aux[j]=false;
            }
        }
    }   
    for(lli i=2;i<=1e6;++i){
        if(aux[i]){
            primes.pb(i);
        }
    }
}

vector<lli> getFactors(lli n){
    vector<lli> factors;
    for(lli i=1;i*i<=n;++i){
        if(n%i==0){
            if(i*i==n){
                factors.pb(i);
            }else{
                factors.pb(i);
                factors.pb(n/i);
            }
        }
    }

    return factors;
}

lli dz,xz,yz;

void extendedEuclid(lli a,lli b){
    if(b==0){
        dz=a;
        xz=1;
        yz=0;
    }else{
        extendedEuclid(b,a%b);
        lli temp=xz;
        xz=yz;
        yz=temp - (a/b)*yz;
    }
}

lli modInverse(lli a,lli m){
    extendedEuclid(a,m);
    lli inv=(xz%m+m)%m;
    if((a%m*inv%m)%m==1){
        return inv;
    }else{
        return -1;
    }
}

lli totient(lli n){
    if(n==1){
        return 1;
    }
    lli aux=n;
    unordered_set<lli> factors;
    lli i=0;
    while(n!=1 && i<primes.size()){
        while(n%primes[i]==0){
            factors.insert(primes[i]);
            n/=primes[i];
        }
        i++;
    }
    if(n!=1){
        factors.insert(n);
    }
    
    lli up=1;
    lli down=1;
    lli modu=1e9+7;
    lli res=1;
    lli inv;

    for(auto x:factors){
        up*=(x-1);
        down*=x;
        inv=modInverse(down,modu);
        if(inv!=-1){
            res*= ((up%modu) *(inv%modu))%modu;
            res%=modu;
            up=1;
            down=1;
        }
    }
    inv=modInverse(down,modu);
    if(inv!=-1){
        res*= ((up%modu) *(inv%modu))%modu;
        res%=modu;
    }else{
        res*=up;
        res/=down;
    }
    res = (res%modu)*(aux%modu);
    return res%modu;

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    criba();
    lli n;
    cin>>n;
    auto factors=getFactors(n);
    lli res=1;
    lli m=1e9+7;
    for(auto x:factors){
        res= ((res%m)*(totient(x)%m))%m;
    }
    cout<<res<<ENDL;

    
    return 0;
}

