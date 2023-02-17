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
    int n,k,a,b;
    cin>>n>>k;
    vector<int> number(n);
    vector<int> color(n);
    for(int i=0;i<n;++i){
        cin>>a>>b;
        color[a-1]=b;
        number[i]=a-1;
    }
    bool si=true;
    FOR(i,0,n){
        if(color[number[i]]!=color[i]){
            si=false;
            break;
        }
    }
    cout<<(si?"Y":"N")<<ENDL;
    return 0;
}
