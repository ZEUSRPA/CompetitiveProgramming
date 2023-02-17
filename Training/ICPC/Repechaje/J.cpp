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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,c,f,b,s;
    cin>>t;
    while(t--){
        cin>>c>>f>>b>>s;
        int aux=s/c;
        s-=aux*c;
        aux*=12;
        int a=0;
        double r=double(b)/12;
        double g=double(f)/12;
        double z=0.0;
        double y=0.0;
        double turn=double(c)/12.0;
        bool si=true;
        while(s-int(turn*a)>0||!si){
            a++;
            z+=r;
            y+=g;
            if(abs(int(a*r)-z)<1e-6&&abs(int(a*g)-y)<1e-6){
                si=true;
            }else{
                si=false;
            }
            if(a==12){
                break;
            }

        }
        cout<<aux+a<<ENDL;
    }
    return 0;
}