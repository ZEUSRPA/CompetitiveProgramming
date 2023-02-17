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
    lli t,n,k;
    string a;
    cin>>t;
    while(t--){
        cin>>n>>k>>a;
        pair<string,lli> best={"0",1};
        vector<lli> starts;
        string b="";

        for(int i=0;i<n;++i){
            string aux=a+b;
            int cmp=aux.compare(best.first);
            if(cmp==0){
                best.second++;
                starts.pb(i);
            }else if(cmp>0){
                best.first=aux;
                best.second=1;
                starts.clear();
                starts.pb(i);
            }
            b+=a[0];
            a.erase(a.begin());
            
        }
        // deb(best.first);
        // deb(best.second);
        // for(auto x:starts){

        //     cout<<x<<" ";
        // }
        if(best.first=="0"){
            cout<<k-1<<ENDL;
        }else{
            lli res=((k-1)/best.second)*n+starts[0];
            lli resi=(k-1)%best.second;
            lli xy=0;
            while(xy<resi){
                res+=starts[xy+1]-starts[xy];
                xy++;
            }
            cout<<res<<ENDL;
        }
        
        
    }
    return 0;
}

