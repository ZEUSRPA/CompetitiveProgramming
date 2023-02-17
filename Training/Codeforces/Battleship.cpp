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

int main()
{

    IO;
    bool si=true;
    int n,d,l,r,c;
    cin>>n;
    vector<vector<int>> grid(11,vector<int>(11,0));
    pair<int,int>pos;
    for(int i=0;i<n;i++){
        cin>>d>>l>>r>>c;
        if(d==0){
            pos.first=0;
            pos.second=1;
        }else{
            pos.first=1;
            pos.second=0;
        }
        for(int j=0;j<l;++j){
            int a=r+j*pos.first;
            int b=c+j*pos.second;
            
            if(a>=0&&a<grid.size()&&b>=0&&b<grid[0].size()){
                grid[a][b]++;
                if(grid[a][b]>1){
                    si=false;
                }
            }else{
                si=false;
            }
        }
    }

    cout<<(si?"Y":"N")<<ENDL;
    return 0;
}