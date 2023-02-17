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


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,x,y;
    cin>>n;
    vector<pair<int,int>> steps={{-1,0},{0,-1},{0,1},{1,0}};
    vector<vector<bool>> grid(26,vector<bool>(26,false));
    vector<pair<int,int>> s;
    int res=0;
    for(int i=0;i<n;++i){
        cin>>x>>y;
        grid[x][y]=true;
        s.pb({x,y});
    }
    for(auto z:s){
        bool si=true;
        for(auto t:steps){
            int a=z.first+t.first;
            int b =z.second+t.second;
            if(a>=0&&a<26&&b>=0&&b<26&&grid[a][b]){
                continue;
            }else{
                si=false;
                break;
            }
        }
        if(si){
            res++;
        }
    }
    cout<<res<<ENDL;
    return 0;
}

