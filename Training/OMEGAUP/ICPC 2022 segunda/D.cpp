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

unsigned lli getMin(vector<vector<pair<unsigned lli,unsigned lli>>> &graph){
    queue<unsigned lli> nex;
    nex.push(1);
    vector<unsigned lli> costs(graph.size(),LLONG_MAX);
    costs[0]=0;
    costs[1]=0;
    unsigned lli lvl=1;
    vector<unsigned lli> lvls(graph.size(),LLONG_MAX);
    unsigned lli res=0;
    while(nex.size()){
        unsigned lli c=nex.size();
        while(c--){
            auto current=nex.front();
            nex.pop();
            for(auto x:graph[current]){
                if(lvls[x.first]>=lvl && x.second*lvl<costs[x.first]){
                    costs[x.first]=x.second*lvl;
                    if(lvls[x.first]>lvl){
                        nex.push(x.first);
                        lvls[x.first]=lvl;
                    }
                }
            }
        }
        lvl++;
    }
    for(auto x:costs){
        res+=x;
    }
    return res;
}

int main()
{
    IO;
    unsigned lli n,m,a,b,c;
    cin>>n>>m;
    vector<vector<pair<unsigned lli,unsigned lli>>> graph(n+1);
    FOR(i,0,m){
        cin>>a>>b>>c;
        graph[a].pb({b,c});
        graph[b].pb({a,c});
    }
    cout<<getMin(graph)<<ENDL;
    return 0;
}