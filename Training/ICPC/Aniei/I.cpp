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
    string s,t;
    int k;
    while(cin>>s){
        cin>>t>>k;
        unordered_map<string,int> aux;
        for(int i=0;i<=s.size()-k;++i){
            aux[s.substr(i,k)]++;
        }
        bool si=false;
        for(int i=0;i<=t.size()-k;++i){
            if(aux.count(t.substr(i,k))){
                si=true;
                break;
            }
        }
        cout<<(si?"yes":"no")<<ENDL;

        
    }
    return 0;
}