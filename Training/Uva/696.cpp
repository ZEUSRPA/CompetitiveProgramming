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
    lli m,n;
    while(cin>>m>>n){
        if(m==0 && n==0){
            break;
        }
        int aux;
        if(m==1 || n==1){
            aux=(m>n?m:n);
        }else if(m==2 || n==2){
            if(m!=2){
                aux=ceil(double(m)/4.0);
                aux*=4;
                if(m%4==1){
                    aux-=2;
                }
            }else{
                aux=ceil(double(n)/4.0);
                aux*=4;
                if(n%4==1){
                    aux-=2;
                }
            }
        }else{
            int a=(n/2)+(n%2);
            int b=n/2;
            int z=(m/2)+(m%2);
            a=a*z;
            b=b*(m/2);
            aux=a+b;
        }
        cout<<aux<<" knights may be placed on a "<<m<<" row "<<n<<" column board."<<ENDL;
    }
    return 0;
}