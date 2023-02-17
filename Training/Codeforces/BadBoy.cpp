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
    int t,n,m,i,j,i1,j1,i2,j2;
    cin>>t;
    while(t--){
        cin>>n>>m>>i>>j;
        if((i==1 && j==1)||(i==1 && j==m) ||(i==n && j==m) ||(i==n && j==1) ){
            if(i==1){
                i1=n;
                i2=n;
            }else{
                i1=1;
                i2=1;
            }
            if(j==1){
                j1=m;
                j2=m;
            }else{
                j1=1;
                j2=1;
            }
        }else{
            i1=1;
            i2=n;
            j1=1;
            j2=m;
        }
        cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<ENDL;
    }
    return 0;
}

