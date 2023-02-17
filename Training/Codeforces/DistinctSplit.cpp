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


int main() {_ 
    lli t,n;
    cin>>t;
    string s;
    while(t--){
        cin>>n;
        cin>>s;
        vector<lli> pref(n);
        vector<lli> rev(n);
        set<char> one;
        set<char> two;
        fore(i,0,n){
            one.insert(s[i]);
            pref[i]=one.size();
            two.insert(s[n-i-1]);
            rev[n-i-1]=two.size();
        }
        lli ans=0;
        fore(i,1,n){
            ans=max(rev[i]+pref[i-1],ans);
        }
        cout<<ans<<ENDL;

    }
    return 0;
}