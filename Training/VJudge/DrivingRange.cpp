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

int getAns(vector<vector<pair<int,int>>> &g){
    int added=0;
    int range=0;
    vector<bool> visited(g.size(),false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> nex;
    nex.push({0,0});
    while(nex.size()){
        auto current=nex.top();
        nex.pop();
        if(!visited[current.second]){
            visited[current.second]=true;
            added++;
            range=max(range,current.first);
            for(auto x:g[current.second]){
                if(!visited[x.first]){
                    nex.push({x.second,x.first});
                }
            }
        }
    }

    if(added!=g.size()){
        return -1;
    }else{
        return range;
    }



}

int main()
{
    IO;
    int n,m,a,b,c;
    while(cin>>n>>m){
        if(n==0&&m==0){
            break;
        }
        vector<vector<pair<int,int>>> g(n);
        FOR(i,0,m){
            cin>>a>>b>>c;
            g[a].pb({b,c});
            g[b].pb({a,c});
        }
        int res=getAns(g);
        cout<<(res==-1?"IMPOSSIBLE":to_string(res))<<ENDL;
    }

    return 0;
}