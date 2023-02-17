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
    int n,s=0,t,m=0,pos;
    cin>>n;
    vector<int> tables(n);
    for(int i=0;i<n;i++){
        cin>>tables[i];
        s+=tables[i];
        if(tables[i]>m){
            m=tables[i];
            pos=i;
        }
    }
    t=s/n;
    long long int r=0;
    long long int cost=0;
    long long int acost=0;
    r=tables[pos]-t;
    int p=pos+1;
    int s=pos;
    p%=n;
    while(p!=s){
        
        if(tables[p]>t){
            r+=(tables[p]-t);
        }else{
            r-=(t-tables[p]);
        }
        r-=(t-tables[p]);

    }
    return 0;
}

