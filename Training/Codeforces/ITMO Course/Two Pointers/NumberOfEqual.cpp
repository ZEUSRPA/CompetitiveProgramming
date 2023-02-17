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
    lli n,m;
    cin>>n>>m;
    vector<lli> one(n);
    vector<lli> two(m);
    FOR(i,0,n){
        cin>>one[i];
    }
    FOR(i,0,m){
        cin>>two[i];
    }
    lli ans=0;
    lli i=0,j=0;
    while(i<n && j<m){
        if(one[i]==two[j]){
            lli a=1;
            lli b=1;
            i++;
            j++;
            while(i<n && one[i]==one[i-1]){
                a++;
                i++;
            }
            while(j<m && two[j]==two[j-1]){
                b++;
                j++;
            }
            ans+=a*b;
        }else if(one[i]<two[j]){
            i++;
        }else{
            j++;
        }
    }
    cout<<ans<<ENDL;
    return 0;
}