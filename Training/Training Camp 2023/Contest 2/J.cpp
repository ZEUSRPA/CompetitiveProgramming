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
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
#define deb(x) cout << #x": " << (x) << endl;

int main() {_
    int n,m;
    cin>>n>>m;
    int x1=1,y1=1,x2=n,y2=m;
    if(n==1&&m==1){
        cout<<1<<" "<<1<<ENDL;
    }else{
        while(x1<x2){
            cout<<x1<<" "<<y1<<ENDL;
            cout<<x2<<" "<<y2<<ENDL;
            y1++;
            y2--;
            if(y1>m){
                x1++;
                x2--;
                y1=1;
                y2=m;
            }
        }   
        while(x1==x2&&m>0){
            cout<<x1<<" "<<y1<<ENDL;
            m--;
            if(m){
                cout<<x2<<" "<<y2<<ENDL;
            }
            m--;
            y1++;
            y2--;
        }

    }

    return 0;
}