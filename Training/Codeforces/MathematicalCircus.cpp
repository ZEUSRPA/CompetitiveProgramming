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
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<pair<int,int>> aux;
        for(int i=1;i<=n;i+=2){
            if(((i+k)*(i+1))%4==0){
                aux.pb({i,i+1});
            }else if(((i+1+k)*(i))%4==0){
                aux.pb({i+1,i});
            } 
        }
        int v=n/2;
        if(1){
            cout<<"YES"<<ENDL;
            for(int i=0;i<aux.size();i++){
                cout<<aux[i].first<<" "<<aux[i].second<<ENDL;
            }
        }else{
            cout<<"NO"<<ENDL;
        }
    }
    return 0;
}