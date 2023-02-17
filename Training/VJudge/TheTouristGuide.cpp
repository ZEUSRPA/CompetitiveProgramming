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

lli getAns(vector<vector<pair<int,int>>> &g,int s,int e,lli t){
    if(s==e)return 0;
    int added=0;
    lli range=0LL;
    vector<lli> distance(g.size(),LLONG_MAX);
    priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>> nex;
    nex.push({0,s});
    while(nex.size()){
        auto current=nex.top();
        nex.pop();
        for(auto x:g[current.second]){
            lli d=t/(x.second-1);
            if(t%(x.second-1)){
                d++;
            }
            d=max(d,current.first);
            if(d<distance[x.first]){
                distance[x.first]=d;
                nex.push({d,x.first});
            }
        }
    }

    return distance[e];



}

int main()
{
    IO;
    int n,r,a,b,c,sn=1;
    while(cin>>n>>r){
        if(n==0&&r==0)break;
        
        vector<vector<pair<int,int>>> g(n+1);
        FOR(i,0,r){
            cin>>a>>b>>c;
            g[a].pb({b,c});
            g[b].pb({a,c});
        }
        cin>>a>>b>>c;
        
        lli trips=getAns(g,a,b,c);
        cout<<"Scenario #"<<sn++<<ENDL;
        cout<<"Minimum Number of Trips = "<<trips<<ENDL<<ENDL;
        


    }
    return 0;
}