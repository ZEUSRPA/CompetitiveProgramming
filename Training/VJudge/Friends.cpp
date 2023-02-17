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

int find(vector<int> &dsu,int a){
    if(dsu[a]==a){
        return a;
    }
    dsu[a]=find(dsu,dsu[a]);
    return dsu[a];
}

void join(vector<int> &dsu,vector<int> &friends, int a, int b){
    int fa=find(dsu,a);
    int fb=find(dsu,b);
    if(fa==fb)return;
    dsu[fb]=fa;
    friends[fa]+=friends[fb];
}

int main()
{
    IO;
    int t,n,m,a,b;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> dsu(n+1);
        vector<int> friends(n+1,1);
        FOR(i,0,n+1){
            dsu[i]=i;
        }
        FOR(i,0,m){
            cin>>a>>b;
            join(dsu,friends,a,b);
        }
        int res=0;
        FOR(i,1,n+1){
            res=max(res,friends[i]);
        }

        cout<<res<<ENDL;

    }
    return 0;
}