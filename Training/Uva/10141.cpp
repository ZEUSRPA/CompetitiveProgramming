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
    int n,p,z=1;
    string s;
    bool rep=false;
    while(cin>>n>>p){
        
        map<string,double> pr;
        int cont=0;
        int mini=0,d;
        string mi;
        double aux;
        if(n==0 && p==0){
             break;
        }
        if(z>1){
            cout<<ENDL;
        }
        cin.ignore();
        FOR(i,0,n){
            getline(cin,s);
            cont++;

        }
        FOR(i,0,p){
            getline(cin,s);
            cin>>aux;
            pr[s]=aux;
            cin>>d;
            if(d>mini){
                mini=d;
                mi=s;
            }else if(d==mini){
                if(pr[s]<pr[mi]){
                    mi=s;
                }
            }
            cin.ignore();
            while(d--){
                getline(cin,s);
            }
        }
        cout<<"RFP #"<<z<<ENDL;
        cout<<mi<<ENDL;
        z++;
    }
    return 0;
}