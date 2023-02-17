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
#define SZ(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;


const lli MAXN=1e5;
vector<lli> coins;
lli dp[MAXN][10];

lli getAns(lli n,int pos){
    if(n==0){
        return 1;
    }
    if(dp[n][pos]!=-1){
        return dp[n][pos];
    }
    lli ans=0;
    fore(i,pos,coins.size()){
        int c=coins[i];
        while(c<=n){
            ans+=getAns(n-c,i+1);
            c+=coins[i];
        }
    }
    dp[n][pos]=ans;
    return dp[n][pos];
}

int main() {_ 
    lli n;
    coins = vector<lli> {50,25,10,5,1};
    memset(dp,-1,sizeof(dp));
    while(cin>>n){
        lli m=getAns(n,0);
        if(m>1){
            cout<<"There are "<<m<<" ways to produce "<<n<<" cents change."<<ENDL;
        }else{
            cout<<"There is only 1 way to produce "<<n<<" cents change."<<ENDL; 
        }
    }
    return 0;
}