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


bool possible(vector<lli> &pos,lli light, lli k,lli f){
    lli aux=0;
    lli last = 0;
    bool com=false;
    fore(i,0,pos.size()){
        bool si=false;
        while(i<pos.size()&&pos[i]-light<=last){
            si=true;
            i++;
        }
        if(!si){
            return false;
        }
        i--;
        last = pos[i]+light;
        aux++;
        if(pos[i]+light>=f){
            com=true;
            break;
        }
    }
    return aux<=k && com;
}

int main() {_ 
    lli n,k,f;
    cin>>n>>k>>f;
    vector<lli> pos(n);
    fore(i,0,n){
        cin>>pos[i];
    }
    sort(pos.begin(),pos.end());
    lli l=0;
    lli r=1e9+10;
    lli ans = 0;
    while(l<=r){
        lli mid = l+(r-l)/2;
        if(possible(pos,mid,k,f)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<ENDL;
    return 0;
}