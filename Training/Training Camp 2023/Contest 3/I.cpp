// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define F first
#define S second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

const lli mod = 1e9+7;
const lli lim =1e9;

lli modExp(lli a, lli b){
    lli res = 1;
    a%=mod;
    while(b>0){
        if(b&1){
            res = ((res%mod)*(a%mod))%mod;
        }
        a = ((a%mod)*(a%mod))%mod;
        b>>=1;
    }
    return res%mod;
}

lli maxpot(lli a , lli b){
    lli res = 1;
    while(b>0){
        if(b&1){
            res = min(lim,res*a);
        }
        a =min(lim, a*a);
        b>>=1;
    }
    return res;
}

int main() {_
    lli t,n,p;
    cin>>t;
    while(t--){
        cin>>n>>p;
        vector<lli> pots(n);
        fore(i,0,n){
            cin>>pots[i];
        }
        sort(pots.rbegin(),pots.rend());
        lli res = 0;
        lli diff = 0;
        lli currentp=pots[0];
        fore(i,0,n){
            if(currentp!=pots[i]){
                diff = min(lim,diff*maxpot(p,currentp-pots[i]));
                currentp=pots[i];
            }
            if(diff==0){
                res=((res%mod)+(modExp(p,pots[i])%mod))%mod;
                diff++;
            }else{
                res=((res%mod)-(modExp(p,pots[i])%mod)+mod)%mod;
                diff--;
            }
        }
        cout<<res<<ENDL;

    }
    return 0;
}