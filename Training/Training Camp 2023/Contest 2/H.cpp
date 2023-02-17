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

const lli MAXN = 40005;

lli dp[202][MAXN][2];

lli getAns(vector<int> &heights, int a, int b,int pos,int color){
    if(pos+1==heights.size())return 0;
    if(dp[pos][a][color]!=-1){
        return dp[pos][a][color];
    }

    lli ans=INT_MAX;
    lli current= 0;
    if(pos+1<heights.size()){
        if(a>=heights[pos+1]){
            current=getAns(heights,a-heights[pos+1],b,pos+1,0);
            if(color!=0){
                current+=min(heights[pos],heights[pos+1]);

            }
            ans = min(ans,current);
        }
        if(b>=heights[pos+1]){
            current=getAns(heights,a,b-heights[pos+1],pos+1,1);
            if(color!=1){
                current+=min(heights[pos],heights[pos+1]);
            }
            ans = min(ans,current);
        }
    }
    dp[pos][a][color]=ans;
    return dp[pos][a][color];
}

int main() {_
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,a,b;
    cin>>n>>a>>b;
    memset(dp,-1,sizeof(dp));
    vector<int> heights(n);
    int tot=0;
    fore(i,0,n){
        cin>>heights[i];
        tot+=heights[i];
    }
    if(tot<=a+b){
        lli ans = INT_MAX;
        if(a>=heights[0]){
            ans = min(ans,getAns(heights,a-heights[0],b,0,0));
        }
        if(b>=heights[0]){
            ans = min(ans,getAns(heights,a,b-heights[0],0,1));
        }
        if(ans>=INT_MAX)ans=-1;
        cout<<ans<<ENDL;

    }else{
        cout<<-1<<ENDL;
    }
    return 0;
}