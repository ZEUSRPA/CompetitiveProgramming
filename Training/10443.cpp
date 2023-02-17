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
    int t,r,c,n;
    int cont=0;
    string s;
    cin>>t;
    while(t--){
        if(cont>0){
            cout<<ENDL;
        }
        cin>>r>>c>>n;
        unordered_map<int,unordered_map<int,char>> current;
        unordered_map<int,unordered_map<int,char>> poste;
        FOR(i,0,r){
            cin>>s;
            FOR(j,0,c){
                current[i][j]=s[j];
            }
        }
        poste=current;
        FOR(d,0,n){
            FOR(i,0,r){
                FOR(j,0,c){
                    if(current[i][j]=='S'){
                        if(current[i+1][j]=='R'||current[i-1][j]=='R'||current[i][j+1]=='R'||current[i][j-1]=='R'){
                            poste[i][j]='R';
                        }
                    }else if(current[i][j]=='R'){
                        if(current[i+1][j]=='P'||current[i-1][j]=='P'||current[i][j+1]=='P'||current[i][j-1]=='P'){
                            poste[i][j]='P';
                        }
                    }else if(current[i][j]=='P'){
                        if(current[i+1][j]=='S'||current[i-1][j]=='S'||current[i][j+1]=='S'||current[i][j-1]=='S'){
                            poste[i][j]='S';
                        }
                    }
                }
            }
            current=poste;
        }
        FOR(i,0,r){
            FOR(j,0,c){
                cout<<current[i][j];
            }
            cout<<ENDL;
        }
        cont++;

    }
    return 0;
}