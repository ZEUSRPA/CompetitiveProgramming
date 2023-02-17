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
unordered_map<int,int> dp;

int minCost(vector<int> &h,int p){
    if(p==h.size()-1){
        return 0;
    }
    if(dp.count(p)){
        return dp[p];
    }
    int aux=minCost(h,p+1)+abs(h[p]-h[p+1]);
    if(p+2<h.size()){
        aux=min(aux,minCost(h,p+2)+abs(h[p]-h[p+2]));
    }
    dp[p]=aux;
    return dp[p];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i=0;i<n;++i){
        cin>>h[i];
    }

    cout<<minCost(h,0);

    return 0;
}

