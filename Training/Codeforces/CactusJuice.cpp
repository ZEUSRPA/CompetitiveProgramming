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

vector<bool> matrix;
vector<int> primes;

void criba(){
    int last=3001;
    for(int i=2;i*i<last;++i){
        if(matrix[i]){
            for(int j=i*i;j<last;j+=i){
                matrix[j]=false;
            }
        }
    }
    for(int i=2;i<last;++i){
        if(matrix[i]){
            primes.pb(i);
        }
    }
}


int getMax(int n){
    int res=0;
    for(int i=2;i<=n;++i){
        set<int> cont;
        int aux=i;
        int p=0;
        while(aux!=1&&p<primes.size()){
            while(aux%primes[p]==0){
                cont.insert(primes[p]);
                aux/=primes[p];
            }
            p++;
        }
        if(aux!=1){
            cont.insert(aux);
        }
        if(cont.size()==2){
            res++;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    matrix=vector<bool> (3001,true);
    matrix[0]=false;
    matrix[1]=false;
    criba();
    int n;
    cin>>n;
    cout<<getMax(n)<<ENDL;
    return 0;
}

