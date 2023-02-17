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
    int n,m,c,aux,s=1;
    while(cin>>n>>m>>c){
        if(n==0 && m==0 && c==0){
            break;
        }
        vector<pair<int,bool>> con(n+1);
        int tot=0;
        int maxi=0;
        bool blown=false;
        FOR(i,1,n+1){
            cin>>con[i].F;
            con[i].S=false;
        }
        FOR(i,0,m){
            cin>>aux;
            if(!con[aux].S){
                tot+=con[aux].F;
                con[aux].S=true;
                if(tot>maxi){
                    maxi=tot;
                }
                if(tot>c){
                    blown=true;
                }
            }else{
                tot-=con[aux].F;
                con[aux].S=false;
            }
        }
        cout<<"Sequence "<<s<<ENDL;
        if(blown){
            cout<<"Fuse was blown."<<ENDL;
        }else{
            cout<<"Fuse was not blown."<<ENDL;
            cout<<"Maximal power consumption was "<<maxi<<" amperes."<<ENDL;
        }
        cout<<ENDL;
        s++;
    }
    return 0;
}