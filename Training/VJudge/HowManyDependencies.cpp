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

void dfs(vector<vector<int>> &g,vector<int> &results,int p){
    int cont=1;
    for(auto x:g[p]){
        if(!results[x]){
           dfs(g,results,x);
        }
        cont+=results[x];
    }
    results[p]=cont;
}

int main()
{
    IO;
    int n,t,x;
    while(cin>>n){
        if(n==0){
            break;
        }
        vector<vector<int>> g(n);
        vector<int>results(n,0);
        for(int i=0;i<n;++i){
            cin>>t;
            for(int j=0;j<t;++j){
                cin>>x;
                g[i].pb(x-1);
            }
        }
        int maxi=0;
        int res=1;
        for(int i=0;i<n;++i){
            if(!results[i]){
                dfs(g,results,i);
            }
            if(results[i]>maxi){
                maxi=results[i];
                res=i+1;
            }
        }
        cout<<res<<ENDL;

    }

    return 0;
}