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
    lli t,n,d,q,k;
    cin>>t;
    string s;
    while(t--){
        cin>>q;
        bool si=false;
        bool other=false;
        lli ss=1,tt=1;
        FOR(i,0,q){
            cin>>d>>k>>s;
            if(d==1){
                for(auto x:s){
                    if(x=='a'){
                        ss+=k;
                    }else{
                        other=true;
                    }
                }
            }else{
                if(!si){
                    for(auto x:s){
                        if(x!='a'){
                            si=true;
                            break;
                        }else{
                            tt+=k;
                        }
                    }
                }
            }
            if(si){
                cout<<"YES"<<ENDL;
            }else{
                if(ss<tt&&!other){
                    cout<<"YES"<<ENDL;
                }else{
                    cout<<"NO"<<ENDL;
                }
            }
        }

    }
    return 0;
}