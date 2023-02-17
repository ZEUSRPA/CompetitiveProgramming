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
    string s;
    cin>>t;
    FOR(i,1,t+1){
        int y=0,x;
        vector<string> cards(53);
        FOR(j,1,53){
            cin>>s;
            cards[j]=s;
        }
        int top=27;
        FOR(j,0,3){
            if(isalpha(cards[top][0])){
                x=10;
            }else{
                x=cards[top][0]-'0';
            }
            y+=x;
            int cont=0;
            FOR(k,top-(10-x),top+1){
                cards.erase(cards.begin()+k-cont);
                cont++;
            }
            top-=cont;
        }
        cout<<"Case "<<i<<": "<<cards[y]<<ENDL;
    }
    return 0;
}