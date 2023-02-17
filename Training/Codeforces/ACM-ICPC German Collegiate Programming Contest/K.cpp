#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
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

int main()
{
    IO;
    int n,d,k;
    cin>>n>>d>>k;
    vector<pair<int,string>> emp(n);
    for(auto &x:emp){
        cin>>x.S>>x.F;
    }
    sort(ALLR(emp));
    int final=0;
    int total=0;
    while(final<emp.size()&&total<d){
        total+=emp[final++].F;
    }
    if(total>=d && final<=k){
        cout<<final<<ENDL;
        for(int i=0;i<final;i++){
            cout<<emp[i].S<<", YOU ARE FIRED!"<<ENDL;
        }
    }else{
        cout<<"impossible"<<ENDL;
    }
    return 0;
}
