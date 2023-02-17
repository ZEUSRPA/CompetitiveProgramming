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
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<lli> aux(n);
        lli total=0;
        FOR(i,0,n){
            cin>>aux[i];
            total+=aux[i];
        }
        lli minans=aux.size();
        lli current=0;
        FOR(i,0,n){
            current+=aux[i];
            lli testmin=i+1;
            if(total%current==0 && testmin<minans){
                int pos=i+1;
                lli actual=0;
                lli counting=0;
                while(pos<aux.size()&&actual<current){
                    actual+=aux[pos];
                    pos++;
                    counting++;
                    if(actual==current){
                        actual=0;
                        testmin=max(testmin,counting);
                        counting=0;
                    }else if(actual>current){
                        break;
                    }
                }
                if(pos==aux.size()&&actual==0){
                    minans=min(minans,testmin);
                }

            }
        }

        cout<<minans<<ENDL;

        
    }
    return 0;
}