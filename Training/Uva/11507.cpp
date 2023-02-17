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
    int l;
    string s;
    while(cin>>l){
        string current="+x";
        vector<string> mov;
        if(l==0){
            break;
        }
        FOR(i,1,l){
            cin>>s;
            mov.pb(s);
        }
        reverse(mov.begin(),mov.end());
        for(auto &x:mov){
            if(x=="+y"){
                if(current=="+x"){
                    current="+y";
                }else if(current=="-x"){
                    current="-y";
                }else if(current=="+y"){
                    current="-x";
                }else if(current=="-y"){
                    current="+x";
                }else if(current=="+z"){
                    current="+y";
                }else if(current=="-z"){
                    current="+y";
                }
            }else if(x=="-y"){
                if(current=="+x"){
                    current="-y";
                }else if(current=="-x"){
                    current="+y";
                }else if(current=="+y"){
                    current="+x";
                }else if(current=="-y"){
                    current="-x";
                }else if(current=="+z"){
                    current="-y";
                }else if(current=="-z"){
                    current="+y";
                }
            }else if(x=="+z"){
                if(current=="+x"){
                    current="+z";
                }else if(current=="-x"){
                    current="-z";
                }else if(current=="+y"){
                    current="+z";
                }else if(current=="-y"){
                    current="-z";
                }else if(current=="+z"){
                    current="-x";
                }else if(current=="-z"){
                    current="+x";
                }
            }else if(x=="-z"){
                if(current=="+x"){
                    current="-z";
                }else if(current=="-x"){
                    current="+z";
                }else if(current=="+y"){
                    current="-z";
                }else if(current=="-y"){
                    current="+z";
                }else if(current=="+z"){
                    current="+x";
                }else if(current=="-z"){
                    current="-x";
                }
            }
        }
        cout<<current<<ENDL;
    }
    return 0;
}