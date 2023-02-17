#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
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

int main()
{
    IO;
    lli n;
    cin>>n;
    vector<pair<double,double>> ans;
    ans.push_back({100.0,0.0});
    ans.push_back({0.0,100.0});
    int times=1000;
    // abs(ans[ans.size()-1].first-ans[ans.size()-2].first)>1e-7 ||abs(ans[ans.size()-1].second-ans[ans.size()-2].second)>1e-7 
    while(times--){
        ans.push_back({(ans[ans.size()-1].first+ans[ans.size()-2].first)/2.0,(ans[ans.size()-1].second+ans[ans.size()-2].second)/2.0});
    }
    if(n<ans.size()){
        cout<<fixed<<setprecision(8)<<ans[n-1].first<<" "<<ans[n-1].second<<ENDL;
    }else{
        cout<<fixed<<setprecision(8)<<ans[ans.size()-1].first<<" "<<ans[ans.size()-1].second<<ENDL;
    }
    return 0;
}