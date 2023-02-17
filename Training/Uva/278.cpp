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
    int t,m,n;
    char c;
    cin>>t;
    while(t--){
        cin>>c>>m>>n;
        if(c=='r'){
            if(m<n){
                cout<<m<<ENDL;
            }else{
                cout<<n<<ENDL;
            }
        }else if(c=='k'){
            int a=(n/2)+(n%2);
            int b=n/2;
            int z=(m/2)+(m%2);
            a=a*z;
            b=b*(m/2);
            cout<<a+b<<ENDL;
        }else if(c=='Q'){
            if(n<m){
                n^=m;
                m^=n;
                n^=m;
            }
            int a=(n/2);
            int b=(m/a);
            int r=(a*b)+(m%a);
            cout<<r<<ENDL;
        }else if(c=='K'){
            cout<<(m/2+m%2)*(n/2+n%2)<<ENDL;
        }
    }
    return 0;
}