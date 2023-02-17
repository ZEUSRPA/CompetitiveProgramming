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
    int k,m,aux,a,mini;
    while(cin>>k){
        if(k==0){
            break;
        }
        cin>>m;
        bool si=true;
        
        map<int,int> courses;
        FOR(i,0,k){
            cin>>aux;
            courses[aux];
        }
        FOR(i,0,m){
            cin>>aux;
            cin>>mini;
            int current=0;
            FOR(j,0,aux){
                cin>>a;
                if(courses.count(a)){
                    current++;
                }
            }
            if(current<mini){
                si=false;
            }
        }
        cout<<(si?"yes":"no")<<ENDL;
    }
    return 0;
}