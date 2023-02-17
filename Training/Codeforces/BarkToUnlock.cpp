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

int main() {_ 
    string p,s;
    cin>>p;
    bool one=false;
    bool two = false;
    int n;
    cin>>n;
    while(n--){
        cin>>s;
        if(s==p){
            one=true;
            two=true;
        }
        if(s[0]==p[1]){
            two=true;
        }
        if(s[1]==p[0]){
            one = true;
        }
    }
    if(one&&two){
        cout<<"YES"<<ENDL;
    }else{
        cout<<"NO"<<ENDL;
    }
    return 0;
}