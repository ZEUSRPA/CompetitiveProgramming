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

vector<pair<lli,lli>> things;

vector<vector<lli>> dp;

lli best(int v,int p){
    if(v<=0){
        return 0;
    }
    if(p>=things.size()){
        return INT_MAX;
    }
    if(dp[v][p]!=-1){
        return dp[v][p];
    }
    lli m=INT_MAX;
    m=min(m,best(v,p+1));
    if(v>=things[p].second){

        m=min(m,best(v-things[p].second,p+1)+things[p].first);
    }

    dp[v][p]=m;
    return dp[v][p];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n,w;
    cin>>n>>w;
    things=vector<pair<lli,lli>>(n,pair<lli,lli>());
    
    lli sum=0;
    for(lli i=0;i<n;++i){
        cin>>things[i].first>>things[i].second;
        sum+=things[i].second;
    }
    dp=vector<vector<lli>>(sum+1,vector<lli>(n+1,-1));
    lli mv=0;

    for(lli i=sum;i>=0;--i ){
        lli aux=best(i,0);
        if(aux<=w){
            mv=i;
            break;
        }
    }
    cout<<mv<<ENDL;

    return 0;
}

