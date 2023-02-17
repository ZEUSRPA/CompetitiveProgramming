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
    int n;
    cin>>n;
    vector<int> pools(n);
    for(int i=0;i<n;++i){
        cin>>pools[i];
    }
    sort(pools.begin(),pools.end());
    vector<int> res(n);
    int i=0,j=n-1;
    int pos=n-1;
    while(i<=j){
        if(i==j){
            res[pos]=pools[j];
        }else{
            res[pos]=pools[j];
            res[pos-1]=pools[i];
        }
        j--;
        i++;
        pos-=2;
    }
    for(int i=0;i<n-1;i++){
        cout<<res[i]<<" ";
    }
    cout<<res[n-1]<<ENDL;



    return 0;
}

