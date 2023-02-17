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

void dfs(vector<string> &path, pair<int,int> pos,string &word, int p){
    if(p==word.size()){
        return;
    }
    unordered_map<string,pii> steps;
    steps["forth"]={-1,0};
    steps["right"]={0,1};
    steps["left"]={0,-1};
    for(auto x:steps){
        int a =pos.first+x.second.first;
        int b=pos.second+x.second.second;
        if(a>=0&&a<path.size()&&b>=0&&b<path[0].size()&&path[a][b]==word[p]){
            if(p==word.size()-1){
                cout<<x.first<<ENDL;
            }else{
                cout<<x.first<<" ";
            }
            dfs(path,{a,b},word,p+1);
        }
    }
}

int main()
{
    IO;
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>m>>n;
        vector<string> path(m);
        FOR(i,0,m){
            cin>>path[i];
        }
        FOR(i,0,m){
            FOR(j,0,n){
                if(path[i][j]=='@'){
                    string word="IEHOVA#";
                    dfs(path,{i,j},word,0);
                }
            }
        }

        
    }
    return 0;
}