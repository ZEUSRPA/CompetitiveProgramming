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
    lli n,k,m;
    cin>>n;
    while(n--){
        unordered_map<char,lli> words;
        cin>>k;
        char c;
        lli p;
        while(k--){
            cin>>c>>p;
            words[c]=p;
        }
        string aux;
        lli price=0;
        cin>>m;
        cin.ignore();
        while(m--){
            getline(cin,aux);
            for(auto x:aux){
                if(words.count(x)){
                    price+=words[x];
                }
            }
        }
        lli dolars=price/100;
        price%=100;
        cout<<(dolars>0?dolars:0)<<"."<<(price<10?"0":"")<<price<<"$"<<ENDL;
    }

    return 0;
}