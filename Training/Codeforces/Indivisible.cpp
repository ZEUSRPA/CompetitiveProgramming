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
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int ans=0;
        int sum=n*(n+1)/2;
        if(n==1){
            cout<<1<<ENDL;
            continue;
        }
        if(sum%n==0){
            cout<<-1<<ENDL;
        }else{
            int par=n;
            int impar=n-1;
            bool im=true;
            fore(i,0,n-1){
                if(im){
                    im=false;
                    cout<<impar<<" ";
                    impar-=2;
                }else{
                    im=true;
                    cout<<par<<" ";
                    par-=2;
                }
            }
            cout<<par<<ENDL;
        }
    }
    return 0;
}