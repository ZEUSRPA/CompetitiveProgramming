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
    IO;
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string res="";
        int cont=0;
        for(int i=1;i<n;++i){
            cont+=3;
            res+='3';
        }
        if((cont+3)%9==0){
            cont+=6;
            res+='9';
        }else{
            res+='3';
        }
        cout<<res<<ENDL;

    }
    return 0;
}