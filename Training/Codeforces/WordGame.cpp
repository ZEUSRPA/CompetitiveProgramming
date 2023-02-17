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

unordered_map<int,unordered_map<int,int>> dp;


int main()
{
    IO;
    int t,n;
    cin>>t;
    string s1,s2;
    while(t--){
        cin>>n;
        unordered_map<string,int> count;
        vector<vector<string>> words (3,vector<string>(n));
        for(int i=0;i<3;++i){
            for(int j=0;j<n;j++){
                cin>>words[i][j];
                count[words[i][j]]++;
            }
        }
        vector<int> points(3);
        for(int i=0;i<3;i++){
            for(int j=0;j<n;++j){
                if(count[words[i][j]]==1){
                    points[i]+=3;
                }else if(count[words[i][j]]==2){
                    points[i]++;
                }
            }
        }
        cout<<points[0]<<" "<<points[1]<<" "<<points[2]<<ENDL;
    }
    return 0;
}