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
    int t;
    cin>>t;
    string a,b;
    while(t--){
        cin>>a>>b;
        int h1=stoi(a.substr(0,2));
        int h2=stoi(b.substr(0,2));
        int m1=stoi(a.substr(3,2));
        int m2=stoi(b.substr(3,2));
        int res=0;
        if(h1>h2){
            res=24-h1+h2;
        }else{
            res=h2-h1;
        }
        m1+=res;
        m1%=60;
        if(m1>m2){
            res+=60-m1+m2;
        }else{
            res+=m2-m1;
        }
        cout<<res<<ENDL;

        
    }
    return 0;
}