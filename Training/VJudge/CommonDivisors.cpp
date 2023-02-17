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
vector<lli>primes;


void sieve(){
    int siz=1e6+1;
    vector<bool> n(siz,true);
    for(int i=2;i*i<siz;i++){
        if(n[i]){
            for(int j=i*i;j<siz;j+=i){
                n[j]=false;
            }
        }
    }
    FOR(i,2,siz){
        if(n[i]){
            primes.pb(i);
        }
    }
}


lli getDivisors(vector<lli> &nums,lli m){
    lli result=1;
    lli gc=m;
    FOR(i,0,nums.size()){
        gc=__gcd(gc,nums[i]);
    }

    unordered_map<lli,lli> aux;
    int pos=0;
    while(pos<primes.size()&&gc!=1){
        while(gc%primes[pos]==0){
            aux[primes[pos]]++;
            gc/=primes[pos];
        }
        pos++;
    }
    if(gc!=1){
        aux[gc]++;
    }
    for(auto x:aux){
        result*=x.second+1;
    }


    return result;
}

int main()
{
    IO;
    sieve();
    int n;
    cin>>n;
    vector<lli> nums(n);
    lli m=LLONG_MAX;
    FOR(i,0,n){
        cin>>nums[i];
        m=min(nums[i],m);
    }

    cout<<getDivisors(nums,m)<<ENDL;

    return 0;
}