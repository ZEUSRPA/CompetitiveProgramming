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
    int n,t,d;
    cin>>n;
    int direction=-1;
    int stop=0;
    int waiting=0;
    FOR(i,0,n){
        cin>>t>>d;
        if(t>=stop){
            if(waiting){
                waiting=0;
                stop+=10;
                direction=direction==1?0:1;
            }
        }

        if(t>=stop){
            stop=t+10;
            direction=d;
        }else if(d==direction){
            stop=t+10;
        }else{
            waiting=1;
        }
    }
    if(waiting){
        stop+=10;
    }
    cout<<stop<<ENDL;
    return 0;
}
