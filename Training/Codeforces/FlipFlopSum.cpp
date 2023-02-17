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
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n;
        vector<lli> aux(n);
        cin>>aux[0];
        bool si=false;
        bool one=aux[0]==-1;
        lli ans = aux[0];
        fore(i,1,n){
            cin>>aux[i];
            ans+=aux[i];
            if(aux[i]==-1){
                if(aux[i-1]==-1){
                    si=true;
                }
                one=true;
            }
        }
        if(si){
            ans+=4;
        }else if(!one){
            ans-=4;
        }
        cout<<ans<<ENDL;

    }
    return 0;
}