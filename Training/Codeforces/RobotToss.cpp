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
    double xa,ya,xb,yb,a,b;
    cin>>xa>>ya>>xb>>yb;
    double m=(yb-ya)/(xb-xa);
    int e;
    cin>>e;
    while(e--){
        cin>>a>>b;
        if(xa>xb&&a>=xb&&a<=xa){
            if(abs(b-(m*a-m*xa+ya))<1e-6){
                cout<<"Yes"<<ENDL;
            }else{
                cout<<"No"<<ENDL;
            }
        }else if(xb>=xa&&a>=xa&&a<=xb){
            if(abs(b-(m*a-m*xa+ya))<1e-6){
                cout<<"Yes"<<ENDL;
            }else{
                cout<<"No"<<ENDL;
            }
        }else{
            cout<<"No"<<ENDL;
        }
        
    }
    return 0;
}

