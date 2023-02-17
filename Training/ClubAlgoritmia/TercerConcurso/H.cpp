#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ulli unsigned long
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
 
const lli MOD = 1e9 + 7;
const lli MX = 1e4 + 5;
 
ulli fac[MX];
 
ulli binPow(ulli x, ulli y)
{
    ulli res = 1;
    x = x % MOD;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}
 
ulli modInverse(ulli n)
{
    return binPow(n, MOD - 2);
}
 
ulli choose(ulli n, ulli r)
{
    if (n < r)
        return 0;
    return (fac[n] * modInverse(fac[r]) % MOD * modInverse(fac[n - r]) % MOD) % MOD;
}
 
int main()
{
    IO;
    int tc;
    cin >> tc;
    fac[0] = 1;
    for (ulli i = 1; i < MX; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
    while (tc--)
    {
        lli n, a, b;
        cin >> n >> a >> b;
        lli ans = 0;
 
        FOR(i, a, b + 1)
        {
            ans = (ans + choose(n, i)) % MOD;
        }
        cout << ans << ENDL;
    }
 
    return 0;
}