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

int getMinWaste(vector<int> &bags,int k){
    if(k<=0){
        return 0-k;
    }
    if(dp.count(k)){
        return dp[k];
    }
    int minwaste=INT_MAX;
    for(auto x:bags){
        minwaste=min(minwaste,getMinWaste(bags,k-x));
    }
    dp[k]=minwaste;
    return dp[k];
}

int main(){
    IO;
    int k,p;
    cin>>k>>p;
    vector<int> bags(p);
    for(int i=0;i<p;++i){
        cin>>bags[i];
    }
    int x;
    while(k--){
        cin>>x;
        cout<<getMinWaste(bags,x)<<ENDL;
    }
    return 0;
}