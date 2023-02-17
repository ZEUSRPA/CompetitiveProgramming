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
    string s;
    while(cin>>s){
        if(s=="0:00"){
            break;
        }
        vector<int> time;
        string aux;
        for(auto x:s){
            if(x==':'){
                time.pb(stoi(aux));
                aux.clear();
            }else{
                aux+=x;
            }
        }
        time.pb(stoi(aux));
        double res;
        res=time[0]*30;
        res+=double(time[1])/2.0;
        if(res>=360){
            res-=360;
        }
        res=abs(res-time[1]*6);
        if(res>180){
            res=360-res;
        }
        cout<<fixed<<setprecision(3)<<(res)<<ENDL;
    }
    return 0;
}