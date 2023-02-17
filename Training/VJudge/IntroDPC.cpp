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

unordered_map<int,unordered_map<int,int>> dp;

int getmax(vector<vector<int>> &act,int day,int activity){
    if(dp.count(day) &&dp[day].count(activity)){
        return dp[day][activity];
    }
    if(day==act.size()){
        return 0;
    }
    int best=0;
    for(int i=0;i<3;++i){
        if(i!=activity){
            best=max(getmax(act,day+1,i)+act[day][i],best);
        }
        
    }
    
    dp[day][activity]=best;
    return dp[day][activity];

}

int main()
{
    IO;
    int n;
    cin>>n;
    vector<vector<int>> act(n,vector<int>(3));
    for(auto &x:act){
        cin>>x[0];
        cin>>x[1];
        cin>>x[2];
    }
    int best=0;
    for(int i=0;i<3;i++){
        best=max(getmax(act,1,i)+act[0][i],best);
    }
    cout<<best<<ENDL;
    return 0;
}