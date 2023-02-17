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
    int t,n,k,p;
    cin>>t;
    while(t--){
        cin>>n>>k;
        k%=n;
        vector<int> aux(n);
        for(int i=0;i<n;++i){
            cin>>aux[i];
        }
        for(int i=0;i<n-1;++i){
            p=i-k;
            if(p<0){
                p+=n;
            }
            cout<<aux[p]<<" ";
        }
        p=aux.size()-1-k;
        if(p<0){
            p+=n;
        }
        cout<<aux[p]<<ENDL;
    }

    return 0;
}



//zeus rene pallares avina
//estudiante de ingenieria informatica
//mi nivel de programacion es basico
//espero comprender las bases del lenguaje para poder aplicarlos en el analisis de datos
