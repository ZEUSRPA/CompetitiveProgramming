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
vector<unordered_map<int,int>> factors;

void criba(){
    for(int i=2;i<matrix.size();++i){
        if(matrix[i]){
            for(int j=i*i;j<matrix.size();j+=i){
                matrix[j]=false;
            }
        }
    }
    for(int i=2;i<matrix.size();++i){
        if(matrix[i]){
            primes.pb(i);
        }
        
    }
}

void fact(int n){
    unordered_map<int,int> aux;
    int i=0;
    while(n!=1&&i<primes.size()){
        while(n%primes[i]==0){
            aux[primes[i]]++;
            n/=primes[i];
        }
        i++;
    }
    if(n!=1){
        aux[n]++;
    }
    factors.pb(aux);
}


vector<int> getD(){
    vector<int> respo;
    
    for(auto &x:factors[0]){
        int res=1;
        bool s=true;
        int cont=x.second;
        for(int i=1;i<factors.size();++i){
            if(factors[i][x.first]==0){
                s=false;
                break;
            }else{
                cont=min(cont,factors[i][x.first]);
            }
        }
        if(s){
            for(int i=0;i<cont;++i){
                res*=x.first;
            }
            int top=respo.size();
            respo.pb(res);
            for(int i=0;i<top;++i){
                respo.pb(res*respo[i]);
            }
        }
    }
    
    return respo;

}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    matrix=vector<bool> (1e6+1,true);
    matrix[0]=false;
    matrix[1]=false;
    criba();
    
    int n,a;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a;
        fact(a);
    }
    auto res=getD();
    sort(res.rbegin(),res.rend());

    for(auto x:res){
        if(!matrix[x]){
            cout<<x<<ENDL;
            return 0;
        }
    }
    cout<<"NO CIVIL WAR"<<ENDL;


    return 0;
}

