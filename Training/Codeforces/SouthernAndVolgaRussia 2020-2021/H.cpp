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
    int n;
    string s;
    cin>>n>>s;
    char current=s[0];
    int free=1;
    int conjuntos=0;
    int conjuntosz=0;
    int amount=1;
    int res=0;
    FOR(i,1,n){
        if(s[i]!=current){
            conjuntos++;
            if(amount==1){
                free++;
                conjuntosz++;
            }else{
                res+=min(free,amount-1);
                free-=min(free,amount-1);
                free++;
                conjuntosz++;
            }
            amount=1;
            current=s[i];
        }else{
            amount++;
        }
    }
    conjuntos++;
    if(amount==1){
        conjuntosz++;
        free++;
    }else{
        res+=min(free,amount-1);
        free-=min(free,amount-1);
        free++;
        conjuntosz++;
    }
    cout<<conjuntos-(conjuntosz-res)/2<<ENDL;
    return 0;
}