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

lli getAns(vector<lli> &aux){
    lli ans = 0;
    const lli lim = (1<<aux.size());
    fore(i,0,lim){
        lli current=0;
        fore(j,0,aux.size()){
            if(i& (1<<j)){
                current|=aux[j];
            }
        }
        ans+=current;
    }
    return ans;
}

int main() {_ 
    lli n;
    cin>>n;
    vector<lli> aux(n);
    fore(i,0,n){
        cin>>aux[i];
    }
    cout<<getAns(aux)<<ENDL;
    return 0;
}