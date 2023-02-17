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

const lli N = 1e6 + 10;

int main()
{
    IO;
    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<pii> aux;
    vector<int> fenwick(N + 10, 0);

    auto update = [&](int i, int val) {
        for (; i < N; i += (i & -i))
        {
            fenwick[i] += val;
        }
    };

    auto query = [&](int i) {
        int val = 0;
        for (; i > 0; i -= (i & -i))
            val += fenwick[i];
        return val;
    };

    // auto rangeQuery = [&](int l, int r) {
    //     if (l == 0)
    //         return query(r);
    //     return query(r) - query(l - 1);
    // };

    /// reading input
    FOR(i, 0, n)
    {
        int val;
        cin >> val;
        aux.pb({val, i + 1});
    }
    sort(ALL(aux));

    // formating input to numbers from 0 to n
    FOR(i, 0, n)
    {
        v[i + 1] = aux[i].S;
    }

    lli ans = 0;
    FORN(i, n + 1, 1)
    {
        // int newPos = 0;
        int newPos = v[i] + query(v[i]);
        // debp(i, v[i]);
        // deb(i);
        // deba("or", v[i]);
        // deba("up", query(v[i]));
        if (newPos != i)
        {
            // cout << "Move" << ENDL;
            ans++;
            update(v[i], -1);
        }
        // cout << ENDL;
    }
    cout << ans << ENDL;

    return 0;
}