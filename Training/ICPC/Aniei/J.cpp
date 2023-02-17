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

vector<lli> ans;
vector<bool> matrix;
vector<lli> primes;
vector<lli> resp;

void criba(){
    int s=1e3+1;
    matrix=vector<bool> (s,true);
    matrix[0]=false;
    matrix[1]=false;
    for(int i=2;i*i<s;++i){
        if(matrix[i]){
            for(int j=i*i;j<s;j+=i){
                matrix[j]=false;
            }
        }
    }

    for(int i=2;i<s;++i){
        if(matrix[i]){
            primes.pb(i);
        }
    }
}

void maping(){
    
}

void calc(){
    
    int m=1e6+1;
    for(int x=1;x<m;++x){
        int dist=x;
        unordered_set<int> aux;
        int i=0;
        while(dist!=1&&i<primes.size()){
            while(dist%primes[i]==0){
                aux.insert(primes[i]);
                dist/=primes[i];
            }
            i++;
        }
        if(dist!=1){
            aux.insert(dist);
        }
        ans[x]=aux.size();
    }
}

lli combinations(int x, int y){
    vector<int> posis;
    lli res=0;
    lli mod=1e9+7;
    for(int i=x;i<y;++i){
        posis.pb(i);
    }
    for(int i=0;i<(1<<posis.size());++i){
        for(int j=0;j<posis.size();++j){
            if(i&(1<<j)){
               res+=ans[y-posis[j]];
               res%=mod;
            }
        }
    }
    return res;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,x,y;
    ans=vector<lli> (1e6+1,-1);
    calc();
    while(true){
        cin>>n>>x>>y;
        if(n==0&&x==0&&y==0){
            break;
        }
        lli res=combinations(x,y);
        cout<<res<<ENDL;

    }
    return 0;
}