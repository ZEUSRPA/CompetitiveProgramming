
#include <bits/stdc++.h> 
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define mp make_pair
#define F first
#define PI       3.14159265358979323846
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
    int n;
    cin>>n;
    vector<double> rad(n);
    for(int i=0;i<n;++i){
        cin>>rad[i];
    }
    sort(rad.rbegin(),rad.rend());
    double red=0.0f;
    bool redi=true;
    for(auto x:rad){
        double aux=x*x*PI;
        if(redi){
            red+=aux;
            redi=false;
        }else{
            red-=aux;
            redi=true;
        }
    }
    cout<<fixed<<setprecision(14)<<red<<ENDL;
    return 0;
}

