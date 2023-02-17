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
    int t,n,k;
    cin>>t;
    string a,b;
    while(t--){
        cin>>n>>k;
        cin>>a;
        cin>>b;
        map<char,int> aux;
        lli current = 0;
        lli ans = 0;
        fore(i,0,n){
            if(a[i]!=b[i]){
                if(aux.count(a[i])){
                    a[i]=b[i];
                }else{
                    if(aux.size()<)
                }
            }else{
                current++;
            }
        }

    }
    return 0;
}