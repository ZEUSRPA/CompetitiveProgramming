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
    vector<int> prices(3);
    FOR(i,0,3){
        cin>>prices[i];
    }
    vector<int> current(3,0);
    sort(prices.begin(),prices.end());
    bool other=true;
    while(n!=0&&other){
        FOR(i,0,3){
            other=false;
            if(n>=prices[i]){
                current[i]++;
                n-=prices[i];
                other=true;
            }
        }
         
    }

    cout<<current[0]+current[1]+current[2]<<ENDL;
    
    return 0;
}