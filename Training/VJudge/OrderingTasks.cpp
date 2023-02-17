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

void dfs(vector<vector<int>> &g, vector<int> &before, vector<int> &res, int p){
    res.pb(p+1);
    before[p]=-1;
    for(auto x:g[p]){
        before[x]--;
    }

}

int main()
{
    IO;
    int n,m,a,b;
    while(cin>>n>>m){
        if(n==0&&m==0){
            break;
        }
        vector<vector<int>> g(n);
        vector<int> before(n,0);
        FOR(i,0,m){
            cin>>a>>b;
            a--;
            b--;
            g[a].pb(b);
            before[b]++;
        }
        vector<int> ans;
        while(ans.size()<n){
            FOR(i,0,n){
                if(before[i]==0){
                    dfs(g,before,ans,i);
                }
            }
        }

        for(auto x:ans){
            cout<<x<<" ";
        }
        cout<<ENDL;

    }
    return 0;
}