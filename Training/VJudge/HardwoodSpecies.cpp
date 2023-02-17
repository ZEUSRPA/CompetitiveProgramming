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
    int t;
    cin>>t;
    cin.ignore();
    string s;
    getline(cin,s);
    int c=1;
    while(t--){
        if(c++>1){
            cout<<ENDL;
        }
        map<string,int> aux;
        int cont=0;
        while(getline(cin,s)){
            if(s==""){
                break;
            }
            aux[s]++;
            cont++;
        }
        for(auto x:aux){
            cout<<fixed<<setprecision(4)<<x.first<<" "<<double(x.second*100)/double(cont)<<ENDL;
        }
    }
    return 0;
}