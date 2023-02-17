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
    lli t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<string> matrix(n);
        lli ones=0;
        for(int i=0;i<n;++i){
            cin>>matrix[i];
        }
        int consecutive=0;
        vector<pair<int,int>> steps={{0,1},{1,0},{1,1},{1,-1}};
        bool finished=false;
        for(int i=0;i<n;++i){
            
            for(int j=0;j<m;j++){
            
                if(matrix[i][j]=='0'){
                    if(!finished){
                        consecutive=1;
                        for(auto x:steps){
                            if(i+x.first<n && j+x.second<m){
                                if(matrix[i+x.first][j+x.second]=='0'){
                                    consecutive=2;
                                    finished=true;
                                    break;
                                }
                            }
                        }
                    }
                }else{
                    ones++;
                }
            }
        }
        lli answer=0;
        if(consecutive==2){
            answer=ones;
        }else if(consecutive==1){
            answer=ones-1;
        }else{
            answer= ones -2;
        }
        //cout<<ones<<ENDL;
        cout<<answer<<ENDL;
    }
    return 0;
}