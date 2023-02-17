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

lli binaryLifting(lli x,lli n, lli m){
    lli result=1;
    while(n){
        if(n%2==1){
            result=(result*x)%m;
        }
        x=(x*x)%m;
        n>>=1;
    }
    return result;
}

bool isPrime(lli x){
    if(x<=3){
        return true;
    }
    lli k=100;
    while(k--){
        lli n=2+(rand()%(x-2));
        if(binaryLifting(n,x-1,x)!=1){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<(isPrime(n)?"No":"Yes")<<ENDL;
    }
    return 0;
}

