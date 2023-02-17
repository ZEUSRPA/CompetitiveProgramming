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

int chainSize(vector<vector<int>> &g,vector<bool> &visited,int p){
    int total=0;
    for(auto x:g[p]){
        if(!visited[x]){
            visited[x]=true;
            total+=chainSize(g,visited,x);
        }
    }
    return total+1;
}

int main()
{
    IO;
    int c,r;
    string s,sb;
    while(cin>>c>>r){
        if(c==0&&r==0){
            break;
        }
        unordered_map<string,int> aux;
        vector<vector<int>> g(c);
        FOR(i,0,c){
            cin>>s;
            aux[s]=i;
        }
        FOR(i,0,r){
            cin>>s>>sb;
            g[aux[s]].pb(aux[sb]);
            g[aux[sb]].pb(aux[s]);
        }
        vector<bool> visited(c,false);
        int res=0;
        FOR(i,0,c){
            if(!visited[i]){
                visited[i]=true;
                res=max(res,chainSize(g,visited,i));
            }
        }
        cout<<res<<ENDL;

    }
    return 0;
}