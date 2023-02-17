#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define lli long long
#define ld long double
#define pii pair<lli, lli>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (lli i = (a); i < (n); ++i)
#define FORN(i, a, n) for (lli i = (a - 1); i >= n; --i)
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;
double getarea(lli a,lli b,lli c){
    double p=(a+b+c)/2.0;
    double area=sqrt(p*(p-a)*(p-b)*(p-c));
    return area;
}
map<lli,map<lli,lli>>dp;
vector<pair<lli,lli>>bags;
lli mini(lli b){
    vector<lli>dp(b+1,1e9);
    for (int i=0; i<=b; i++)
      for (int j=0; j<bags.size(); j++){
          if(i==0){
              dp[i]=0;
          }else
            if (bags[j].first <= i){
            dp[i] = min(dp[i], (dp[i-(bags[j].first)] + bags[j].second));
            //deb(dp[i]);
         }else{
            dp[i]=min(dp[i],bags[j].second);
         }
           //cout<<i<<ENDL;
            //cout<<dp[i]<<ENDL;
      }
    
    return dp[b];
}
bool comp(pair<lli,lli>&a,pair<lli,lli>&b){
    if(a.first==0){
        return false;
    }else if(b.first==0){
        return true;
    }
    return a.second/a.first<b.second/b.first;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli a,b,c,c2,d,e,f;
    cin>>a>>b;
    while(a--){
        cin>>c>>c2;
        bags.push_back({c,c2});
    }
    sort(bags.begin(),bags.end(),comp);
    
    double sum=0;
    while(b--){
        cin>>d>>e>>f;
        sum+=getarea(d,e,f);
    }
    lli ans=mini(ceil(sum/30.0));
    if(ans>1e8){
        cout<<-1<<ENDL;
    }else
    cout<<ans<<ENDL;
    return 0;
}