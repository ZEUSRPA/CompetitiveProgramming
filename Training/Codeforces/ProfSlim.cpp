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
    int t,n,aux;
    cin>>t;

    while(t--){
        bool si=true;
        int prev=INT_MIN;
        int neg=0;
        cin>>n;
        vector<int> aux(n);
        for(int i=0;i<n;++i){
            cin>>aux[i];
            if(aux[i]<0){
                neg++;
            }
        }
        if(neg){
            aux[0]=abs(aux[0])*-1;
            neg--;
        }
        for(int i=1;i<n;++i){
            if(neg){
                aux[i]=abs(aux[i])*-1;
                neg--;
            }else{
                aux[i]=abs(aux[i]);
            }
            if(aux[i]<aux[i-1]){
                si=false;
            }

        }
        cout<<(si?"YES":"NO")<<ENDL;
    }
    return 0;
}