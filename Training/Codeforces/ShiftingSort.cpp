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
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> aux(n);
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            cin>>aux[i];
        }
        int cont=0;
        for(int i=0;i<n;++i){
            int mi=i;
            for(int j=i+1;j<n;++j){
                if(aux[j]<aux[mi]){
                    mi=j;
                }
            }
            
            if(mi!=i){
                int prev=aux[mi];
                for(int j=i;j<=mi;++j){
                    swap(prev,aux[j]);
                }
                cont++;
                vector<int> ax(3);
                ax[0]=i+1;
                ax[1]=mi+1;
                ax[2]=mi-i;
                res.pb(ax);
            }
            
        }
        cout<<cont<<ENDL;
        for(auto x:res){
            cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<ENDL;
        }
    }
    return 0;
}

