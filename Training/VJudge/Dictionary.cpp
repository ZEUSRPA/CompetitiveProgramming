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
    string s;
    unordered_map<string,int> aux;
    char one='a';
    char two='a';
    int current=1;
    while(current<=650){
        if(one!=two){
            s=one;
            s+=two;
            aux[s]=current++;
        }
        two++;
        if(two>'z'){
            one++;
            two='a';
        }
    }




    while(t--){
        cin>>s;
        cout<<aux[s]<<ENDL;
    }
    return 0;
}