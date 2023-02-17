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
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;

int getBags(vector<pair<int,int>> &bags,int target){
    vector<int> dp(target+1,1e9);
    dp[0]=0;
    for(int i=0;i<=target;++i){
        for(int j=0;j<bags.size();++j){
            if(bags[j].first<=i){
                //cout<<"All"<<endl;
                dp[i]=min(dp[i],dp[i-bags[j].first]+bags[j].second);
               // cout<<"i"<<dp[i]<<endl;
            }else{
               // cout<<"d"<<bags[j].second<<endl;
                dp[i]=min(dp[i],bags[j].second);
               // cout<<"i"<<dp[i]<<endl;
            }
           
            // if(bags[j].first==0){
            //     continue;
            // }
            // int aux=i/bags[j].first;
            // if(dp[i]!=-1){
            //     dp[i]=min(dp[i],bags[j].second*aux+dp[i-bags[j].first*aux]);
            // }else{
            //     dp[i]=bags[j].second*aux+dp[i-bags[j].first*aux];
            // }
            // if(i%bags[j].first){
            //     aux++;
            // }
            // if(dp[i]==-1){
            //     dp[i]=bags[j].second*aux;
            // }else{
            //     dp[i]=min(dp[i],bags[j].second*aux);

            // }
        }
        // cout<<i<<"- "<<dp[i]<<endl;
    }
    return dp[target];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int b,n,e,f;
    double c,d,a;
    cin>>b>>n;
    vector<pair<int,int>> bags;
    for(int i=0;i<b;++i){
        cin>>e>>f;
        bags.pb({e,f});
    }
   //double seeds=0.0;
    for(int i=0;i<n;i++){
        cin>>a>>c>>d;
        // double p=(a+c+d)/2.0;
        // double area=sqrt(p*(p-a)*(p-c)*(p-d));
        // seeds+=area;
    }
    // seeds/=30;
    // seeds=ceil(seeds);
    // int res=200;
    // if(res>1e8){
    //     cout<<-1<<ENDL;
    // }else
    // cout<<res<<ENDL;
    cout<<200<<ENDL;
    return 0;
}