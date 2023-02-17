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
    int n;
    string s;
    while(cin>>n){
        if(n==-1){
            break;
        }
        set<char> letters;
        cin>>s;
        for(auto x:s){
            letters.insert(x);
        }
        cin>>s;
        int win=0,fail=0;
        for(auto x:s){
            if(letters.find(x)!=letters.end()){
                letters.erase(letters.find(x));
                if(letters.size()==0){
                    win=1;
                    break;
                }
            }else{
                fail++;
                if(fail==7){
                    win=2;
                    break;
                }
            }
        }
        cout<<"Round "<<n<<ENDL;
        if(win==1){
            cout<<"You win."<<ENDL;
        }else if(win==2){
            cout<<"You lose."<<ENDL;
        }else{
            cout<<"You chickened out."<<ENDL;
        }

    }
    return 0;
}