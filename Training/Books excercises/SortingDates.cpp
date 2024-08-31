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
    int n;
    scanf("%d",&n);
    cout<<n<<ENDL;
    vector<string> dates(n,string(90,' '));
    fore(i,0,n){
        scanf("%2s, %2s, %4s",dates[i].begin()+3,dates[i].begin(),dates[i].begin()+6);
    }
    sort(ALL(dates));
    fore(i,0,n){
        printf("%2s,%2s,%4s\n",dates[i].begin()+3,dates[i].begin(),dates[i].begin()+6);
    }
    
    return 0;
}