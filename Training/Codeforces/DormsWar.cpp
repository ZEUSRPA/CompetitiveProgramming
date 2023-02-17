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
    int t,n,k;
    char aux;
    cin>>t;
    string s;
    while(t--){
        cin>>n;
        cin>>s;
        unordered_map<char,int> mapin;
        cin>>k;
        for(int i=0;i<k;++i){
            cin>>aux;
            mapin[aux]++;
        }
        vector<int> pos;
        for(int i=0;i<s.size();++i){
            if(mapin.count(s[i])){
                pos.pb(i);
            }
        }
        int res=0;
        if(pos.size()){
            res=pos[0]-0;
        }
        for(int i=1;i<pos.size();++i){
            res=max(res,pos[i]-pos[i-1]);
        }
        cout<<res<<ENDL;

    }
    return 0;
}