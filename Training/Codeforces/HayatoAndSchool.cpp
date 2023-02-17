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
    int t,n,aux;
    cin>>t;
    while(t--){
        cin>>n;
        int pos = -1;
        vector<int> odd;
        vector<int> even;
        fore(i,0,n){
            cin>>aux;
            if(aux%2){
                 pos=i;
                 odd.pb(i+1);
            }else{
                even.pb(i+1);
            }
        }
        if(even.size()>=2 && odd.size()>=1){
            cout<<"YES"<<ENDL;
            cout<<even[0]<<" "<<even[1]<<" "<<odd[0]<<ENDL;
        }else if(odd.size()>=3){
            cout<<"YES"<<ENDL;
            cout<<odd[0]<<" "<<odd[1]<<" "<<odd[2]<<ENDL;
        }else{
            cout<<"NO"<<ENDL;
        }
    }
    return 0;
}