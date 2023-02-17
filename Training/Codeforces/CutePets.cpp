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
    int n,a,b;
    cin>>n;
    bool res=false;
    vector<pair<int,int>> op;
    while(n--){
        cin>>a>>b;
        op.pb({a,b});
    }
    sort(op.begin(),op.end());
    for(int i=1;i<op.size();++i){
        if(op[i].first>op[i-1].first&&op[i].second<=op[i-1].second){
            res=true;
            break;
        }
    }
    cout<<(res?"yes":"no")<<ENDL;

    return 0;

}

