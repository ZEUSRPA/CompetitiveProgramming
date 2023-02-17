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



lli pairwise(lli n){
    lli sum=0;
    lli s=1;
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            if(i*i==n){
                sum+=s*i;
                s+=i;
            }else{
                sum+=s*i;
                s+=i;
                sum+=(n/i)*s;
                s+=(n/i);
            }
        }
    }
    if(n!=1){
        sum+=s*n;
    }
    return sum;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<pairwise(n)<<ENDL;
    }
    return 0;
}

