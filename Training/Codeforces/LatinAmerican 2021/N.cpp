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
    cin>>n;
    string s;
    lli total=0;
    lli cents=0;
    lli ans=0;
    fore(i,0,n+1){
        cin>>s;
        string aux="";
        for(auto x:s){
            if(x=='$'){
                aux="";
            }else if(x=='.'){
                total+=stoll(aux);
                aux="";
            }else{
                aux+=x;
            }
        }
        cents+=stoll(aux);
        total+=(cents/100);
        cents%=100;
        if(i>0&&cents !=0){
            ans++;
        }
    }
    cout<<ans<<ENDL;
    return 0;
}