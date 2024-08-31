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
#define pii pair<lli, lli>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (lli i = (a); i < (n); ++i)
#define FORN(i, a, n) for (lli i = (a - 1); i >= n; --i)
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;
int maxn = 1e6+3;
vector<int> prim(maxn, 1);
vector<int> primes;
void criba()
{

    for (int i = 2; i * i < maxn; i++)
    {
        // cout<<i<<endl;
        if (prim[i] == 0)
            continue;
        for (int j = i * i; j < maxn; j += i)
        {
            // cout<<j<<endl;
            prim[j] = 0;
        }
    }
    for (int i = 2; i < maxn; i++)
    {
        if (prim[i])
        {
            primes.pb(i);
        }
    }
}

int main()
{
    IO;
    criba();
    lli n,k;
    cin>>n;
    FOR(i,0,n){
        cin>>k;
        lli t=k;
        lli sum=1;
        for(auto p:primes){
            if(p>k)break;
            lli cont=p;
            while(k%p==0){
                cont*=p;
                k/=p;
            }
            sum*=(cont-1)/(p-1);
        }
        if(k>1){
            sum*=(k*k-1)/(k-1);
        }
        if(sum-t>=t-1 && t%2==0 || t==1){
            cout<<"Yes"<<ENDL;
        }else{
            cout<<"No"<<ENDL;
        }
    }
    return 0;
}
