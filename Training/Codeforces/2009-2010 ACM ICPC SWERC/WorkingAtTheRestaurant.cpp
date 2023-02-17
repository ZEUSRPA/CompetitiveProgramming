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
    int n;
    int c=0;
    while(cin>>n){
        if(n==0){
            break;
        }
        if(c++!=0){
            cout<<ENDL;
        }
        int p1=0,p2=0;
        string s;
        int m;
        FOR(i,0,n){
            cin>>s>>m;
            if(s=="DROP"){
                cout<<"DROP 2 "<<m<<ENDL;
                p2+=m;
            }else{
                if(p1==0){
                    cout<<"MOVE 2->1 "<<p2<<ENDL;
                    p1=p2;
                    p2=0;
                }
                if(p1>=m){
                    cout<<"TAKE 1 "<<m<<ENDL;
                    p1-=m;
                }else{
                    cout<<"TAKE 1 "<<p1<<ENDL;
                    m-=p1;
                    cout<<"MOVE 2->1 "<<p2<<ENDL;
                    p1=p2;
                    p2=0;
                    cout<<"TAKE 1 "<<m<<ENDL;
                    p1-=m;
                }
                // if(m>0){
                    
                //     p1=p2;
                //     p2=0;
                //     cout<<"TAKE 1 "<<m<<ENDL;
                //     p1-=m;
                // }
                // if(p1>=m){
                //     deb(p1);
                //     cout<<"TAKE 1 "<<m<<ENDL;
                //     p1-=m;
                //     deb(p1);

                // }else{
                    
                // }
            }
        }
    }
    return 0;
}