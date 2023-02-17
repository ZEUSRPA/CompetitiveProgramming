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
unsigned lli getMin(vector<pair<lli,lli>> &mosters, vector<pair<lli,lli>>& neighbors){
    priority_queue<pair<lli,pair<lli,lli>>,vector<pair<lli,pair<lli,lli>>>, greater<pair<lli,pair<lli,lli>>>> nex;
    FOR(i,0,mosters.size()){
        lli multi=0;
        if(neighbors[i].first!=-1){
            multi++;
        }
        if(neighbors[i].second<neighbors.size()){
            multi++;
        }
        nex.push({mosters[i].second*multi, {min((long long int)i,mosters.size()-i-1),i}});
    }
    vector<bool> killed(mosters.size(),false);
    unsigned lli total=0;
    while(nex.size()){
        auto current=nex.top();
        nex.pop();
        if(!killed[current.second.second]){
            killed[current.second.second]=true;
            total+=mosters[current.second.second].first;
            total+=current.first;
            
            
            lli multi=0;
            if(neighbors[current.second.second].first!=-1){
                lli leftneighbor=neighbors[current.second.second].first;
                neighbors[leftneighbor].second=neighbors[current.second.second].second;
                if(neighbors[leftneighbor].first!=-1){
                    multi++;
                }
                if(neighbors[leftneighbor].second<neighbors.size()){
                    multi++;
                }
                nex.push({mosters[leftneighbor].second*multi,{min(leftneighbor,mosters.size()-leftneighbor-1),leftneighbor}});
                
            }
            multi=0;
            if(neighbors[current.second.second].second<neighbors.size()){
                lli rightneighbor=neighbors[current.second.second].second;
                neighbors[rightneighbor].first=neighbors[current.second.second].first;
                if(neighbors[rightneighbor].first!=-1){
                    multi++;
                }
                if(neighbors[rightneighbor].second<neighbors.size()){
                    multi++;
                }
                nex.push({mosters[rightneighbor].second*multi,{min(rightneighbor,mosters.size()-rightneighbor-1),rightneighbor} });
            }
        }
    }
    return total;
}

int main()
{
    IO;
    lli t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<lli,lli>> mosters(n);
        vector<pair<lli,lli>> neighbors(n);
        FOR(i,0,n){
            cin>>mosters[i].first;
            neighbors[i].first=i-1;
            neighbors[i].second=i+1;
        }
        FOR(i,0,n){
            cin>>mosters[i].second;
        }
        cout<<getMin(mosters,neighbors)<<ENDL;

    }
    return 0;
}