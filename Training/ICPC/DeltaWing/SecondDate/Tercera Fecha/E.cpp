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
    int n,t,d;
    cin>>n;
    pair<int,int> right={-1,-1};
    pair<int,int>left={-1,-1};
    for(int i=0;i<n;++i){
        cin>>t>>d;
        if(d==0){
            if(right.second>t){
                if(right.first<=t){
                    right.second=t+10;
                    if(left.first>=right.first&&left.first<=right.second){
                        left.second+=(right.second-left.first);
                        left.first=right.second;
                    }
                }
            }else{
                if(t<left.second){
                    right.first=left.second;
                    right.second=right.first+10;
                }else{
                    right.first=t;
                    right.second=t+10;
                }
            }
        }else{
            if(left.second>t){
                if(left.first<=t){
                    left.second=t+10;
                    if(right.first>=left.first&&right.first<=left.second){
                        right.second+=(left.second-right.first);
                        right.first=left.second;
                    }
                }
            }else{
                if(t<right.second){
                    left.first=right.second;
                    left.second=left.first+10;
                }else{
                    left.first=t;
                    left.second=t+10;
                }
            }
        }
    }
    cout<<max(right.second,left.second)<<ENDL;
    return 0;
}