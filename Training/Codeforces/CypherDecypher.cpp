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
vector<int> primes;
vector<bool> criba;

void doCriba(){
    for(int i=2;i*i<criba.size();i++){
        if(criba[i]){
            for(int j=i*i;j<criba.size();j+=i){
                criba[j]=false;
            }
        }
    }
    int aux=0;
    for(int i=0;i<primes.size();++i){
        if(criba[i]){
            aux++;
        }
        primes[i]=aux;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    primes=vector<int> (1e6+1,0);
    criba=vector<bool> (1e6+1,true);
    criba[0]=false;
    criba[1]=false;
    doCriba();
    int t,i,j;
    cin>>t;
    while(t--){
        cin>>i>>j;
        cout<<primes[j]-primes[i-1]<<ENDL;
    }
    return 0;
}

