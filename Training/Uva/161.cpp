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
    int a,b,c;
    while(cin>>a>>b>>c){
        if(a==0&&b==0&&c==0){
            break;
        }
        vector<int> times;
        times.pb(a);
        times.pb(b);
        while(c!=0){
            times.pb(c);
            cin>>c;
            sort(times.begin(),times.end());
            int t=0;
            while(t<=18000){
                int dif=0;
                t+=times[0]*2;
                FOR(i,1,times.size()){
                    if(times[i]){

                    }
                }
            }
        }

    }
    return 0;
}