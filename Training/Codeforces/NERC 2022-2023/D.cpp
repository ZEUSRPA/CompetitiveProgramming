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

lli fact(lli n){
    lli ans=1;
    fore(i,1,n+1){
        ans*=i;
    }
    return ans;
}

int main() {_ 
    lli n,x;
    cin>>n;
    fore(i,0,n){
        cin>>x;
    }
    lli ans=0;
    n= 10-n;
    lli aux = fact(n-2);
    n=fact(n);
    lli k=2LL*aux;
    k=n/k;
    k*=20;
    cout<<k<<ENDL;
    return 0;
}