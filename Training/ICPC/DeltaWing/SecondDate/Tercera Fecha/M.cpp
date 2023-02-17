#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define mp make_pair
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
vector<bool> visited;
int dfs(vector<pair<pair<int,int>,vector<int>>>&aux,int p){
    if(aux[p].first.first==1){
        return p;
    }
    for(auto x:aux[p].second){
        if(visited[x]==false){
            auto res=dfs(aux,x);
            if(res!=-1){
                return res;
            }
        }
    }
    visited[p]=true;
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q,t,x;
    cin>>q;
    vector<pair<pair<int,int>,vector<int>>> aux(1);
    aux[0].first={1,-1};
    int current=0;
    visited=vector<bool> (1e5+1,false);
    while(q--){
        cin>>t>>x;
        x--;
        if(t==1){
            aux[x].second.pb(aux.size());
            aux.pb({{1,x},vector<int>()});
        }else{
            aux[x].first.first=-1;
            if(x==current){
                current=dfs(aux,x);
                while(current==-1){
                    visited[x]=true;
                    x=aux[x].first.second;
                    current=dfs(aux,x);
                }
            }
            cout<<current+1<<ENDL;
        }
    }
    return 0;
}