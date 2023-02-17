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
    int t,a,b,c;
    cin>>t;
    string s;
    while(t--){
        cin>>a>>b>>c;
        bool si=true;
        int cont=0;
        int ys=0;
        while(a--){
            cin>>s;
            for(auto x:s){
                x=tolower(x);
                if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'){
                    cont++;
                }else if(x=='y'){
                    ys++;
                }
            }
        }
        if(ys<5-cont||cont>5){
            si=false;
        }
        ys=0;
        cont=0;
        while(b--){
            cin>>s;
            for(auto x:s){
                x=tolower(x);
                if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'){
                    cont++;
                }else if(x=='y'){
                    ys++;
                }
            }
        }
        if(ys<7-cont||cont>7){
            si=false;
        }
        ys=0;
        cont=0;
        while(c--){
            cin>>s;
            for(auto x:s){
                x=tolower(x);
                if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'){
                    cont++;
                }else if(x=='y'){
                    ys++;
                }
            }
        }
        if(ys<5-cont||cont>5){
            si=false;
        }

        cout<<(si?"YES":"NO")<<ENDL;

    }
    return 0;
}