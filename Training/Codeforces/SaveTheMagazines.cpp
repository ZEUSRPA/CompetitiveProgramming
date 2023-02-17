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
    int t,n;
    cin>>t;
    string s;
    while(t--){
        cin>>n>>s;
        lli total=0;
        vector<int> magazines(n);
        FOR(i,0,n){
            cin>>magazines[i];
        }
        FOR(i,0,n){
            if(s[i]=='0'){
                int pos=i+1;
                bool si=false;
                while(pos<n&&s[pos]=='1'){
                    if(magazines[pos]<=magazines[i]){
                        si=true;
                        break;
                    }
                    pos++;
                }
                if(si){
                    swap(s[i],s[pos]);
                }
            }
        }
        FOR(i,0,n){
            if(s[i]=='1'){
                total+=magazines[i];
            }
        }
        cout<<total<<ENDL;
        
    }
    return 0;
}