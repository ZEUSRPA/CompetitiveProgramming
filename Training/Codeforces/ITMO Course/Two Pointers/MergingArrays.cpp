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
    int n,m;
    cin>>n>>m;
    vector<int> one(n);
    vector<int> two(m);
    vector<int> three(m+n);
    FOR(i,0,n){
        cin>>one[i];
    }
    FOR(i,0,m){
        cin>>two[i];
    }
    int i=0,j=0,k=0;
    while(i<n || j<m){
        if(j==m || (i<n && one[i]<two[j])){
            three[k++]=one[i++];
        }else{
            three[k++]=two[j++];
        }
    }
    FOR(i,0,three.size()){
        cout<<three[i]<<" ";
    }
    cout<<ENDL;
    return 0;
}