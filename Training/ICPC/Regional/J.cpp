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
    int n,k,r,auxi;
    cin>>n>>k;
    char c;
    vector<vector<int>> comp;
    while(n--){
        cin>>c;
        if(c=='C'){
            comp.pb(vector<int>(k+1,0));
            cin>>r;
            for(int i=0;i<r;++i){
                cin>>auxi;
                comp[comp.size()-1][auxi]++;
            }

        }else if(c=='J'){
            cin>>r;
            vector<int> aux(k+1);
            for(int i=0;i<r;++i){
                cin>>auxi;
                aux[auxi]++;
            }
            int cont=0;
            for(auto x:comp){
                bool si=true;
                for(int i=1;i<aux.size();i++){
                    if(aux[i]>x[i]){
                        si=false;
                        break;
                    }
                }
                if(si){
                    cont++;
                }
            }   
            cout<<cont<<ENDL;
        }else{
            cin>>r;
            for(auto &x:comp[r-1]){
                x=0;
            }
        }

    }
    return 0;
}

