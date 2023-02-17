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

lli cont=0;

bool getAns(lli n,lli x){
    cont++;
    if(n>=x){
        return false;
    }
    bool si=false;
    fore(i,2,10){
        if(getAns(n*i,x)==false){
            si=true;
            break;
        }
    }
    return si;
}

int main() {_ 
    int n;
    while(cin>>n){
        if(getAns(1,n)){
            cout<<"Stan wins."<<ENDL;
        }else{
            cout<<"Ollie wins."<<ENDL;
        }
    }
    return 0;
}