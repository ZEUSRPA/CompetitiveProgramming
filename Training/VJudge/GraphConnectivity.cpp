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


void bfs(vector<vector<int>> &g,vector<bool> &visited,int p){
    queue<int> nex;
    nex.push(p);
    visited[p]=true;
    while(nex.size()){
        int current=nex.front();
        nex.pop();
        for(auto x:g[current]){
            if(!visited[x]){
                visited[x]=true;
                nex.push(x);
            }
        }
    }
}

int main()
{
    IO;
    int t;
    cin>>t;
    cin.ignore();
    string s;
    getline(cin,s);
    int cas=1;
    while(t--){
        getline(cin,s);
        vector<vector<int>> g(s[0]-'A'+1);
        if(cas++!=1){
            cout<<ENDL;
        }
        while(getline(cin,s)){
            if(s=="")break;
            g[s[0]-'A'].pb(s[1]-'A');
            g[s[1]-'A'].pb(s[0]-'A');
        }
        vector<bool> visited(g.size(),false);
        int cont=0;

        FOR(i,0,g.size()){
            if(!visited[i]){
                bfs(g,visited,i);
                cont++;
            }
        }
        cout<<cont<<ENDL;


    }

    return 0;
}