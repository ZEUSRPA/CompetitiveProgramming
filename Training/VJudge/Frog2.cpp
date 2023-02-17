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
int k;
vector<int> h;
unordered_map<int,int> dp;
int cost(int p){
    if(p>=h.size()-1){
        return 0;
    }
    if(dp.count(p)){
        return dp[p];
    }
    int c=INT_MAX;
    for(int i=1;i<=k;++i){
        if(p+i<h.size()){
            c=min(c,cost(p+i)+abs(h[p]-h[p+i]));
        }
    }
    dp[p]=c;
    return dp[p];

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n>>k;
    h=vector<int> (n);
    for(int i=0;i<n;++i){
        cin>>h[i];
    }
    cout<<cost(0)<<ENDL;
    return 0;
}

