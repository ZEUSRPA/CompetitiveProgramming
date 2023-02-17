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
    int n;
    cin>>n;
    vector<lli> strength(n);
    vector<int> amount(2);
    string coloring="";
    FOR(i,0,n){
        cin>>strength[i];
        strength[i]=((strength[i])%3*(strength[i])%3)%3;
        amount[strength[i]]++;
    }

    if(amount[0]>=n/2){
        int c=0;
        cout<<2<<ENDL;
        FOR(i,0,n){
            if(strength[i]==0&&c<n/2){
                cout<<0;
                c++;
            }else{
                cout<<1;
            }
        }
    }else{
        cout<<0<<ENDL;
        int c=0;
        FOR(i,0,n){
            if(strength[i]==1&&c<n/2){
                cout<<1;
                c++;
            }else{
                cout<<0;
            }
        }
    }
    cout<<ENDL;
    return 0;
}