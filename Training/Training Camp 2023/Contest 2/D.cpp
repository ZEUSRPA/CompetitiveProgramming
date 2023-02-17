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


const lli MAXN=20,MAXC=5;

lli dp[MAXN][MAXC][2];

lli getAns(int pos,lli cont, int flag,vector<int> &positions){
    if(cont>3)return 0;
    if(pos==-1){
        if(cont<=3){
            return 1;
        }else{
            return 0;
        }
    }
    if(dp[pos][cont][flag]!=-1){
        return dp[pos][cont][flag];
    }
    lli ans = 0;
    int mx = (flag==1?9:positions[pos]);
    fore(i,0,mx+1){
        int ff = (flag==1?1:(i==positions[pos]?0:1));
        ans+=getAns(pos-1,(i!=0?cont+1:cont),ff,positions);
    }

    dp[pos][cont][flag]=ans;
    return dp[pos][cont][flag];

}

int main() {_
    lli t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        a--;
        vector<int> pos(20,0);  
        vector<int> posb(20,0);
        int i=0;
        while(a){
            pos[i]=a%10;
            a/=10;
            i++;
        }
        i=0;
        while(b){
            posb[i]=b%10;
            b/=10;
            i++;
        }
        memset(dp,-1,sizeof(dp));
        lli aa=getAns(18,0,0,pos);
        // deb(aa);
        memset(dp,-1,sizeof(dp));
        lli bb=getAns(18,0,0,posb);
        // deb(bb);
        lli ans=bb;
        ans-=aa;
        cout<<ans<<ENDL;

    }
    return 0;
}