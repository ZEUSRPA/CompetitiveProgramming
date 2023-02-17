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

bool valid(vector<vector<int>> &rooks){
    FOR(i,0,rooks.size()){
        int one=0;
        int two=0;
        FOR(j,0,rooks.size()){
            if(rooks[i][j]==0){
                one++;
            }
            if(rooks[j][i]==0){
                two++;
            }
        }
        if(one==rooks.size()){
            return true;
        }
        if(two==rooks.size()){
            return true;
        }
    }
    
    return false;
}


int main()
{
    IO;
    int t,n,m,a,b;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> rooks(n,vector<int>(n,0));
        FOR(i,0,m){
            cin>>a>>b;
            rooks[a-1][b-1]=1;
        }
        bool si=valid(rooks);
        
        cout<<(si?"YES":"NO")<<ENDL;
        

    }
    return 0;
}