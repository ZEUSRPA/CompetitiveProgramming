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

lli getAns(vector<vector<pair<int,int>>> &g){
    int added=0;
    lli range=0LL;
    vector<bool> visited(g.size(),false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> nex;
    nex.push({0,1});
    while(nex.size()){
        auto current=nex.top();
        nex.pop();
        if(!visited[current.second]){
            visited[current.second]=true;
            added++;
            range+=current.first;
            for(auto x:g[current.second]){
                if(!visited[x.first]){
                    nex.push({x.second,x.first});
                }
            }
        }
    }

    return range;



}

int main()
{
    IO;
    int n,ca=1,a,b,c,oldcost,k,m;
    while(cin>>n){
        if(ca++!=1){
            cout<<ENDL;
        }
        oldcost=0;
        vector<vector<pair<int,int>>> g(n+1);
        FOR(i,0,n-1){
            cin>>a>>b>>c;
            oldcost+=c;
        }
        cin>>k;
        FOR(i,0,k){
            cin>>a>>b>>c;
            g[a].pb({b,c});
            g[b].pb({a,c});

        }
        cin>>m;
        FOR(i,0,m){
            cin>>a>>b>>c;
            g[a].pb({b,c});
            g[b].pb({a,c});

        }

        cout<<oldcost<<ENDL;
        cout<<getAns(g)<<ENDL;

    }
    return 0;
}