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
    int n;
    cin>>n;
    int y = 5;
    string first;
    cout<<0<<" "<<y<<ENDL;
    cin>>first;
    n--;
    int l=1,r=1e9;
    string ans;
    while(n){
        int m=l+(r-l)/2;
        cout<<m<<" "<<y<<ENDL;
        cin>>ans;
        if(ans==first){
            l=m+1;
        }else{
            r=m-1;
        }
        n--;
    }
    if(r==1e9){
        cout<<l<<" "<<y-1<<" "<<l<<" "<<y+2<<ENDL;
    }else{
        cout<<l-1<<" "<<y-1<<" "<<r+1<<" "<<y+1<<ENDL;
    }
    return 0;
}