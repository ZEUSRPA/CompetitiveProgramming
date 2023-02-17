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
    double h,u,d,f;
    while(cin>>h>>u>>d>>f){
        double c=0.0;
        int day=0;
        double fa=double(u)*double(f)/100.0;
        bool si=false;
        if(h==0){
            break;
        }
        while(c<=h){
            day++;
            c+=u;
            u-=fa;
            if(u<0){
                u=0;
            }
            if(c>h){
                si=true;
                break;
            }
            c-=d;
            if(c<0){
                break;
            }
            
        }
        if(si){
            cout<<"success on day "<<day<<ENDL;
        }else{
            cout<<"failure on day "<<day<<ENDL;
        }


    }
    return 0;
}