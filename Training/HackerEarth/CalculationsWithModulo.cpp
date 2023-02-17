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

lli d,x,y;

lli binaryExponentiation(lli x,lli b,lli m){
    lli result=1;
    while(b>0){
        if(b%2==1){
            result = (result * x)%m;
        }
        x=(x*x)%m;
        b/=2;
    }
    return result;

}

void extendedEuclid(lli c, lli m){
    if(m==0){
        d=c;
        x=1;
        y=0;
    }else{
        extendedEuclid(m,c%m);
        lli temp=x;
        x=y;
        y=temp-(c/m)*y;
    }
}

lli modInverse(lli c,lli m){
    extendedEuclid(c,m);
    return (x%m+m)%m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli a,b,c,m;
    cin>>a>>b>>c>>m;
    cout<<(binaryExponentiation(a,b,m)*modInverse(c,m))%m<<ENDL;

    return 0;
}

