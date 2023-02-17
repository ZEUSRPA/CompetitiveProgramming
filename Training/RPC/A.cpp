#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define INF 1000000000
using namespace std;

int main()
{
  IO;
  int s, c;

  cin >> s;
  vector<pii> slots(s);
  FOR(i, 0, s)
  cin >> slots[i].F >> slots[i].S;

  cin >> c;
  map<int, bool> taken;
  vector<pii> coins(c);
  FOR(i, 0, c)
  {
    cin >> coins[i].F >> coins[i].S;
    taken[i] = false;
  }

  sort(ALL(coins));
  lli total = 0;

  FOR(i, 0, s)
  {
    if (coins.size() <= 0)
      break;

    pii search = {slots[i].F, INF};
    auto end = upper_bound(ALL(coins), search);
    int amount = end - coins.begin();
    for (int j = 0; j < amount; j++)
    {
      if (!taken[j] && coins[j].S >= slots[i].S)
      {
        taken[j] = true;
        total += i + 1;
      }
    }
  }
  cout << total << ENDL;
  return 0;
}