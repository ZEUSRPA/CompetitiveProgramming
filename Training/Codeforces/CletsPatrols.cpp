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
    int n,m;
    cin>>n>>m;
    vector<double> res(n,0.0);
    res[0]=1.0;
    vector<vector<double>> prob(n,vector<double>(n));
    FOR(i,0,n){
        FOR(j,0,n){
            cin>>prob[i][j];
        }
    }
    FOR(i,0,m){
        vector<double> aux=res;
        FOR(x,0,n){
            double tmp=0.0;
            FOR(j,0,n){
                tmp+=aux[j]*prob[j][x];
            }
            res[x]=tmp;
        }
    }
    FOR(i,0,n){
        cout<<res[i]<<ENDL;
    }
    return 0;
}