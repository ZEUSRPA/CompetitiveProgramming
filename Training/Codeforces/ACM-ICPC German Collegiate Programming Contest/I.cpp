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

unordered_map<int,int> res;

int dp(vector<int> &slides,int n,int m,int pos){
    if(pos>=slides.size()){
        return 0;
    }

    if(res.count(pos)){
        return res[pos];
    }
    int current=dp(slides,n,m,pos+1);
    current=max(current,dp(slides,n,m,pos+m)+slides[pos]);

    res[pos]=current;
    return res[pos];

}


int main()
{
    IO;
    int n,m;
    cin>>n>>m;
    vector<int> slides(n+1);
    for(int i=1;i<n+1;i++){
        cin>>slides[i];
    }

    cout<<dp(slides,n,m,m+1)<<ENDL;
    return 0;
}
