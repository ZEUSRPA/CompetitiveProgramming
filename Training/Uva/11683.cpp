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
    int a,c,aux;
    while(cin>>a>>c){
        int mini=0;
        if(a==0){
            break;
        }
        vector<bool> states(a+1,false);
        FOR(i,0,c){
            cin>>aux;
            FOR(j,1,aux+1){
                states[j]=false;
            }
            FOR(j,aux+1,a+1){
                if(!states[j]){
                    states[j]=true;
                    mini++;
                }
            }
        }
        cout<<mini<<ENDL;
    }
    return 0;
}