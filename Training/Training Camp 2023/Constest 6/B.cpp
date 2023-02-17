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
    freopen("people.in","r",stdin);
    freopen("people.out","w",stdout);
    lli n;
    cin>>n;
    vector<pair<lli,pair<lli,lli>>> members(n);
    fore(i,0,n){
        cin>>members[i].first;
        cin>>members[i].second.first;
        members[i].second.second=i;
    }
    sort(members.begin(),members.end(),[](pair<lli,pair<lli,lli>> a, pair<lli,pair<lli,lli>> b){
        if(a.first==b.first){
            return a.second.first>b.second.first;
        }
        return a.first<b.first;
        });

    lli last = 0;
    vector<lli> dp(n+1,LLONG_MAX);
    vector<lli> positions(n+1,-1);
    vector<lli> parent(n+1,-1);
    dp[0]=LLONG_MIN;
    fore(i,0,n){
        lli pos = upper_bound(dp.begin(),dp.end(),members[i].second.first)-dp.begin();
        if(dp[pos-1]<members[i].second.first && members[i].second.first < dp[pos]){
            dp[pos]=members[i].second.first;
            positions[pos]=i;
            parent[i]=positions[pos-1];
        }
    }

    lli ans = 1;
    fore(i,1,n+1){
        if(dp[i]<LLONG_MAX){
            ans=i;
        }
    }
    cout<<ans<<ENDL;
    
    // lli current = positions[ans];
    // cout<<members[current].second.second+1<<" ";
    // ans--;
    lli start = positions[ans];
    while(ans--){
        cout<<members[start].second.second+1<<" ";
        start=parent[start];
        // ans--;
    }
    cout<<ENDL;

    return 0;
}