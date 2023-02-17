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
    int t,n,aux;
    cin>>t;
    while(t--){
        deque<int> res;
        cin>>n;
        int m=INT_MAX;
        for(int i=0;i<n;i++){
            cin>>aux;
            if(aux<=m){
                res.push_front(aux);
                m=aux;
            }else{
                res.push_back(aux);
            }
        }
        while(res.size()>1){
            cout<<res.front()<<" ";
            res.pop_front();
        }
        cout<<res.front()<<ENDL;

    }
    return 0;
}

