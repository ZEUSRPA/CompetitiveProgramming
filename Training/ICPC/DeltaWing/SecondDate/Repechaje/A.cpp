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
    int t;
    cin>>t;
    cin.ignore();
    string s;
    unordered_map<int,char> aux;
    aux[3]='E';
    aux[0]='O';
    aux[1]='I';
    aux[4]='A';
    aux[9]='P';
    aux[8]='B';
    aux[5]='S';
    aux[7]='T';
    aux[2]='Z';
    aux[6]='G';

    while(t--){
        getline(cin,s);
        for(auto &x:s){
            if(isdigit(x)){
                x=aux[x-'0'];
            }
        }
        cout<<s<<ENDL;
    }
    return 0;
}