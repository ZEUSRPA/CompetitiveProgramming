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
    int t,n,x,y;
    cin>>t;
    while(t--){
        cin>>n>>x>>y;
        if(x>y){
            swap(x,y);
        }
        if(x!=0||y==0){
            cout<<-1<<ENDL; 
        }else{
            if((n-1)%y){
                cout<<-1<<ENDL;
            }else{
                int current=1;
                int next=2;
                FOR(i,0,(n-1)/y){
                    FOR(j,0,y){
                        cout<<current<<" ";
                        next++;
                    }
                    current=next;
                    
                }
                cout<<ENDL;
            }
            
        }




    }
    return 0;
}
