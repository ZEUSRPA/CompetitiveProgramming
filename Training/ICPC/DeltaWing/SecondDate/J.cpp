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

vector<pair<int,pair<int,int>>> act;
vector<int> dp;
int getHappiness(int pos,int &et){
    if(dp[pos]!=-1){
        return dp[pos];
    }
    int res=0;
    int time=act[pos].first+act[pos].second.second;
    for(int i=pos+1;i<act.size();++i){
        if(act[i].first>et){
            break;
        }
        if(act[i].first>=time){
            res=max(res,getHappiness(i,et));
        }
    }
    res+=act[pos].second.first;
    dp[pos]=res;
    return dp[pos];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,tt,h,d,t,aux;
    cin>>a>>tt;

    for(int i=0;i<a;++i){
        cin>>h>>d>>t;
        for(int j=0;j<t;++j){
            cin>>aux;
            act.pb({aux,{h,d}});
        }
    }
    sort(act.begin(),act.end());
    dp=vector<int> (act.size(),-1);
    int res=0;
    for(int i=0;i<act.size();++i){
        if(act[i].first>tt){
            break;
        }
        res=max(res,getHappiness(i,tt));
    }
    cout<<res<<ENDL;
    return 0;

}

