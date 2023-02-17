#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
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

vector<int> dp;

int getMin(int n,int a,int b){
    if(n%b==0){
        return 0;
    }
    if(n%(a+b)==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int minimo=n;
    if(n>=(a+b)){
        minimo=min(minimo,getMin(n-(a+b),a,b));
    }
    if(n>=b){
        minimo=min(minimo,getMin(n-b,a,b));
    }

    dp[n]=minimo;
    return dp[n];


}

int main()
{
    IO;
    int a,n,b;
    cin>>n>>a>>b;
    n-=2*b;
    n-=a;
    dp=vector<int> (n+1,-1);
    cout<<getMin(n,a,b)<<ENDL;
    return 0;
}