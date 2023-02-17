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
int main()
{
    lli a;
    cin >> a;
    while (a--)
    {
        lli n, q, e, f;
        cin >> n >> q;
        lli ax;
        vector<lli> dat;
        vector<lli> val(n, 0);
        vector<pii> que;
        while (n--)
        {
            cin >> ax;
            dat.push_back(ax);
        }
        while (q--)
        {
            cin >> e >> f;
            que.push_back({f, e-1});
        }
        sort(que.begin(), que.end());
        lli t = 0;
        pii an = {0, dat[0]};
        for (int i = 1; i < dat.size(); i++)
        {
            if (an.second > dat[i])
            {
                val[an.first]++;
            }
            else
            {
                an.first = i;
                an.second = dat[i];
                val[an.first]++;
            }
            while (t < que.size() && que[t].first == i)
            {
                cout << val[que[t].second] << ENDL;
                t++;
            }
        }
        for (; t < que.size(); t++)
        {
            if (que[t].second == an.first)
            {
                cout << val[an.first] + (que[t].first - dat.size())<<ENDL;
            }
            else
            {
                cout << val[que[t].second] << ENDL;
            }
        }
    }
    return 0;
}
