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
#define SZ(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

vector<lli> parent;
vector<lli> ranking;

lli find(lli x){
    if(parent[x]==x){
        return x;
    }
    parent[x]=find(parent[x]);
    return parent[x];
}

void join(lli x, lli y){
    lli px=find(x);
    lli py=find(y);
    if(px==py){
        return;
    }
    parent[px]=py;
    ranking[py]+=ranking[px];
    ranking[px]=0;
}

int main() {_ 
    lli n,m,a,b;
    cin>>n>>m;
    parent = vector<lli>(n+1);
    ranking = vector<lli>(n+1,1);
    fore(i,1,n+1){
        parent[i]=i;
    }
    fore(i,0,m){
        cin>>a>>b;
        join(a,b);
    }
    lli ans=0;
    fore(i,1,n+1){
        if(ranking[i]!=0){
            ans+=ranking[i]-1;
        }
    }
    lli res=1;
    fore(i,0,ans){
        res*=2;
    }
    cout<<res<<ENDL;
    return 0;
}