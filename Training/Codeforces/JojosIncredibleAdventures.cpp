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
    lli t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        lli tot=0;
        lli prev=-1;
        lli current=0;
        lli ans=0;
        bool zero=false;
        bool one=false;
        fore(i,0,sz(s)){
            if(s[i]=='1'){
                one=true;
                current++;
            }else{
                if(prev==-1){
                    prev=current;
                }
                zero=true;
                tot=max(current,tot);
                current=0;
            }
        }
        
        tot=max(current,tot);
        if(prev!=-1&&current!=0){
            current+=prev;
            tot=max(current,tot);

        }
        if(zero){
            lli pro=1;

            for(lli i=tot;i>0;i--){
                ans=max(i*pro,ans);
                pro++;
            }

        }else{
            if(one){
                ans=(lli)sz(s)*(lli)sz(s);
            }
        }
        cout<<ans<<ENDL;
    }
    return 0;
}