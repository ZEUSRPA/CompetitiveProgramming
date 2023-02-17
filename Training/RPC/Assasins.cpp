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
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;

int main()
{
  IO;
  long double n, m;
  cin >> n >> m;
  long double mx[20][20];

  vector<long double> actual(n,1.0);
  vector<long double> total(n,1.0);
//   vector<long double> absLive(n, 1.0);
//   vector<vector<long double>> absDamage(n + 1, vector<long double>(n + 1, 1.0));
  FOR(i, 0, m)
  {
    int a, b;
    long double p;
    cin >> a >> b >> p;
    total[b-1]=total[b-1]-(total[b-1]*actual[a-1]*p);
    actual[b-1]=1.0-p;
    
  }
  FOR(i, 0, n)
  {
    cout << fixed << setprecision(12) << total[i] << ENDL;
  }

  return 0;
}