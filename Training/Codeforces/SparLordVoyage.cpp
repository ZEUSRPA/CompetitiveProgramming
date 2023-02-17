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

vector<int> rocks;

vector<int> dp;

int getR(int p,int &k){
    if(p>=rocks.size()){
        return 0;
    }
    if(dp[p]!=-1){
        return dp[p];
    }

    int res=0;
    res=max(getR(p+1,k),res);
    res=max(getR(p+k+1,k)+rocks[p],res);
    res=max(getR(p+(k/2)+1,k)+rocks[p]/2,res);
    dp[p]=res;
    return dp[p];
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    rocks.resize(n);
    dp=vector<int> (n,-1);
    for(int i=0;i<n;++i){
        cin>>rocks[i];
    }
    cout<<getR(0,k)<<ENDL;
    return 0;
}

