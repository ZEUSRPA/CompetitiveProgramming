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
    string one,two;
    unordered_map<char,int> vals;
    vals['S']=0;
    vals['M']=1;
    vals['L']=2;
    while(t--){
        cin>>one>>two;
        if(one[one.size()-1]==two[two.size()-1]){
            if(one.size()==two.size()){
                cout<<'='<<ENDL;
            }else if(one[one.size()-1]=='S'){
                cout<<(one.size()<two.size()?'>':'<')<<ENDL;
            }else{
                cout<<(one.size()<two.size()?'<':'>')<<ENDL;
            }
        }else{
            cout<<(vals[one[one.size()-1]]<vals[two[two.size()-1]]?'<':'>')<<ENDL;
        }
    }
    return 0;
}