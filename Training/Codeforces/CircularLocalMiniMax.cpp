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
    IO;
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> aux(n);
        for(int i=0;i<n;++i){
            cin>>aux[i];
        }
        sort(aux.begin(),aux.end());
        bool si=true;
        vector<int> res(n);
        if(n%2==0){
            int j=0;
            for(int i=0;i<n/2;++i){
                res[j++]=aux[i];
                res[j++]=aux[n/2+i];
            }
            for(int i=1;i<n-1;++i){
                if(res[i]>=res[i-1]&&res[i]<=res[i+1]||res[i]<=res[i-1]&&res[i]>=res[i+1]){
                    si=false;
                    break;
                }
            }
            if(res[0]>=res[res.size()-1]&&res[0]<=res[1]||res[0]<=res[res.size()-1]&&res[0]>=res[1]){
                si=false;
            }
            if(res[res.size()-1]>=res[res.size()-2]&&res[res.size()-1]<=res[0]||res[res.size()-1]<=res[res.size()-2]&&res[res.size()-1]>=res[0]){
                si=false;
            }
        }else{
            si=false;
        }
        cout<<(si?"YES":"NO")<<ENDL;
        if(si){
            for(int i=0;i<n/2;++i){
                cout<<aux[i]<<" "<<aux[i+n/2]<<" ";

            }
            cout<<ENDL;
        }
    }
    return 0;
}
