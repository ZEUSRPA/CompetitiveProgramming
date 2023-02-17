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

int getAns(int n){
    int res=1;
    int div=1;
    FOR(i,2,n+1){
        res*=i;
    }
    return res*2;
}

int main()
{
    IO;
    int t,n,aux;
    cin>>t;
    
    while(t--){
        cin>>n;
        FOR(i,0,n){
            cin>>aux;
        }
        int factorial=1;
        FOR(i,2,11-n){
            factorial*=i;
        }
        cout<<(factorial/getAns(10-n-2))*6<<ENDL;
    }
    return 0;
}