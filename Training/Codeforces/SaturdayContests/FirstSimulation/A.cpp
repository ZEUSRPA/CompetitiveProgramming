// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
#define deb(x) cout << #x": " << (x) << endl;
// 今日は貸さないけど、明日は貸すよ

int main(){_
    map<lli, int> repetitions;
    int n, m; cin >> n >> m;
    vi enter(n);
    fore(i, 0, n) cin >> enter[i];

    vi out(m);
    fore(i, 0, m) cin >> out[i];

    for(lli i : enter) {
        for(lli j : out) {
            if (j < i) continue;
            if (repetitions.count(j - i) == 0) {
                repetitions[j - i] = 1;
            } else {
                repetitions[j - i]++;
            }
        }
    }
    pair<lli, int> ans = {-1, -1};
    for(auto x : repetitions) {
        if (x.ss > ans.ss) {
            ans.ff = x.ff;
            ans.ss = x.ss;
        }

    }
    cout << ans.ff << ENDL;
    return 0;
}