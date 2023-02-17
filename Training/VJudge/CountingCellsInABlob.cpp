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


int count(vector<string> &blob,vector<vector<bool>> &visited,pair<int,int> current){
    int cont=0;
    vector<pair<int,int>> steps={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    for(auto x:steps){
        int a=current.first+x.first;
        int b=current.second+x.second;
        if(a>=0&&a<blob.size()&&b>=0&&b<blob[0].size()&&blob[a][b]=='1'&&!visited[a][b]){
            visited[a][b]=true;
            cont+=count(blob,visited,{a,b});
        }
    }
    return cont+1;
}

int main()
{
    IO;
    int t;
    cin>>t;
    string s;
    int c=1;
    cin.ignore();
    getline(cin,s);
    while(t--){
        if(c++!=1){
            cout<<ENDL;
        }
        vector<string> blob;
        while(getline(cin,s)){
            if(s==""){
                break;
            }
            blob.pb(s);
        }
        int res=0;
        vector<vector<bool>> visited(blob.size(),vector<bool>(blob[0].size(),false));
        for(int i=0;i<blob.size();++i){
            for(int j=0;j<blob[0].size();++j){
                if(blob[i][j]=='1'&&!visited[i][j]){
                    visited[i][j]=true;
                    res=max(res,count(blob,visited,{i,j}));
                }
            }
        }
        cout<<res<<ENDL;

    }
    return 0;
}