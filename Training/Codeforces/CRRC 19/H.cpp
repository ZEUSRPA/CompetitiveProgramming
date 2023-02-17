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
int getAns(int n){
    vector<bool> states(n+1,false);
    vector<int> moves={1,5,13};
    for(int i=2;i<=n;i++){
        for(auto x:moves){
            int p=i-x;
            if(p>=1){
                if(!states[p]){
                    states[i]=true;
                }
            }
        }
    }
    return states[n]?1:2;
} 

int main()
{
    IO;
    int n;
    cin>>n;
    cout<<getAns(n)<<ENDL;
    return 0;
}
