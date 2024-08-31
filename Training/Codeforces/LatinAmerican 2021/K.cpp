// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define F first
#define S second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define ALL(s) begin(s), end(s)
#define ALLR(s) rbegin(s), rend(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

lli const mod=1e9+7;
lli const MAXN=800;
lli const MAXM=1e4+100;

lli dp[MAXM][MAXN];

int main() {_ 
    memset(dp,0,sizeof(dp));
    lli k,l,n;
    cin>>k>>l;
    k++;
    vector<vector<lli>> key(k,vector<lli>(k,0));
    fore(i,1,k){
        fore(j,1,k){
            cin>>key[i][j];
        }
    }
    cin>>n;
    vector<lli> times(n);
    fore(i,1,n){
        cin>>times[i];
    }
    fore(i,1,k){
        dp[n][i]=i;
    }
    for(int i=n-1;i>=1;i--){
        fore(j,1,k){
            dp[i][j]=dp[i][j-1];
            lli pos1 = upper_bound(ALL(key[j]),times[i]+l)-key[j].begin();
            lli pos2 = lower_bound(ALL(key[j]),times[i]-l)-key[j].begin();
            lli val1=dp[i+1][pos1-1];
            lli val2=dp[i+1][pos2-1];
            dp[i][j]=(dp[i][j]+val1-val2+mod)%mod;
        }
    }
    cout<<dp[1][k-1]<<ENDL;

    return 0;
}