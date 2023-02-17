// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define F first
#define S second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
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
    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        int maxi=0;
        unordered_map<char,int> aux;
        if(s.size()<2){
            cout<<0<<ENDL;
        }else{
            for(auto x:s){
                aux[x]++;
                if(aux[x]>maxi){
                    maxi=aux[x];
                }
            }
            cout<<s.size()-maxi<<ENDL;
        }

        

    }
    return 0;
}