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
    int t,n;
    cin>>t;
    string s;
    int c=1;
    while(c<=t){
        cin>>n;
        cin>>s;
        int res=0;
        int hand=-1;
        int i=0;
        while(i<s.size()){
            if(hand==-1){
                if(s[i]=='O'){
                    hand=2;
                }else if(s[i]=='X'){
                    hand=1;
                }
            }else{
                if(hand==1&&s[i]=='O'){
                    hand=2;
                    res++;
                }else if(hand==2&&s[i]=='X'){
                    hand=1;
                    res++;
                }
            }
            i++;

        }
        cout<<"Case #"<<c++<<": "<<res<<ENDL;
    }
    return 0;
}