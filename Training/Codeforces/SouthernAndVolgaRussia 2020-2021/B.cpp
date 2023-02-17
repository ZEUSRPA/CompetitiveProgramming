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
    int n;
    string s;
    cin>>n;
    cin>>s;
    vector<pair<int,int>> soldiers(n,{0,0});
    soldiers[0].first=s[0]=='L'?1:0;
    soldiers[n-1].second=s[n-1]=='R'?1:0;
    FOR(i,1,n){
        if(s[i]=='L'){
            soldiers[i].first=soldiers[i-1].first+1;
        }else{
            soldiers[i].first=soldiers[i-1].first;
        }
        if(s[n-i-1]=='R'){
            soldiers[n-i-1].second=soldiers[n-i].second+1;
        }else{
            soldiers[n-i-1].second=soldiers[n-i].second;
        }


    }
    int res=INT_MAX;
    FOR(i,0,n){
        int aux=soldiers[i].first+soldiers[i].second;
        aux--;
        res=min(res,aux);
    }
    cout<<res<<ENDL;
    return 0;
}