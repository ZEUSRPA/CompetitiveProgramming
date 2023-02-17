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

int lcs(vector<char> &a,vector<char> &b){
    int res=0;
    vector<vector<int>> ab(a.size()+1,vector<int>(b.size()+1,0));
    for(int i=1;i<=a.size();++i){
        for(int j=1;j<=b.size();++j){
            if(a[i-1]==b[j-1]){
                ab[i][j]=ab[i-1][j-1]+1;
                res=max(res,ab[i][j]);
            }else{
                ab[i][j]=max(ab[i-1][j],ab[i][j-1]);
            }
        }
    }
    return res;
}

int dp(vector<int> &a,vector<int> &b, int x, int y){
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n;++i){
        cin>>b[i];
    }

    cout<<lcs(a,b)<<ENDL;
    
    return 0;
}

