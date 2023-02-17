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
    lli t,a,b,c,d;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        lli res=0;
        if((a==0 && c!=0)||(c==0&& a!=0)){
            res=1;
        }else if(a==0&&c==0){
            res=0;
        }else{
            lli aa,cc;
            aa=a*d;
            cc=b*c;
            if(aa==cc){
                res=0;
            }else{
                if(aa>cc){
                    if(aa%cc==0){
                        res=1;
                    }else{
                        res=2;
                    }
                }else{
                    if(cc%aa==0){
                        res=1;
                    }else{
                        res=2;
                    }
                }
            }
        }
        cout<<res<<ENDL;
    }
    return 0;
}