// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define F first
#define S second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define ALL(s) begin(s), end(s)
#define ALLR(s) rbegin(s), rend(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

int primes[1000009];

void criba(){
    primes[0]=0;
    primes[1]=0;
    for(int i=2;i*i<1000009;i++){
        if(primes[i]){
            for(int j=i+i;j<1000009;j+=i){
                primes[j]=0;
            }
        }
    }
}

int main() {_ 
    int n;
    cin>>n;
    memset(primes, 1, sizeof(primes));
    criba();
    for(int i=1;i<1001;i++){
        if(primes[n*i+1]==0){
            cout<<i<<ENDL;
            break;
        }
    }
    return 0;
}