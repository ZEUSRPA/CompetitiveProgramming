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
    IO;
    int t,n,aux;
    cin>>t;
    
    while(t--){
        cin>>n;
        unordered_map<int,int> nums;
        bool par=false;
        int zero=0;
        for(int i=0;i<n;++i){
            cin>>aux;
            nums[aux]++;
            if(aux==0){
                zero++;
            }
            if(nums[aux]==2){
                par=true;
            }
        }
        int res=0;
        if(zero){
            res=n-zero;
        }else if(par){
            res=n;
        }else{
            res=n+1;
        }
        
        cout<<res<<ENDL;
    }
    return 0;
}