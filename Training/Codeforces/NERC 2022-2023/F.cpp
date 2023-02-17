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
    lli n;
    cin>>n;
    string s;
    cin>>s;
    vector<lli> values(n);
    fore(i,0,n){
        cin>>values[i];
    }
    lli ans = 0;
    int pos = 0;
    while(pos<n){
        if(s[pos]=='0'){
            int aux = pos+1;
            while(aux<n && s[aux]=='1'){
                if(values[aux]<=values[pos]){
                    ans+=values[pos];
                    s[aux]='0';
                    break;
                }
                ans+=values[aux];
                aux++;
            }
            pos=aux;
        }else{
            ans+=values[pos];
            pos++;
        }
    }
    cout<<ans<<ENDL;
    return 0;
}