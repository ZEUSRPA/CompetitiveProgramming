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
    int s,b,l,r;
    while(true){
        cin>>s>>b;
        if(s==0&&b==0){
            break;
        }
        vector<pair<int,int>> soldiers(s+1);
        for(int i=1;i<=s;++i){
            soldiers[i].first=(i==1?-1:i-1);
            soldiers[i].second=(i==s?-1:i+1);
        }
        while (b--)
        {
            cin>>l>>r;
            cout<<(soldiers[l].first!=-1?to_string(soldiers[l].first):"*")<<" "<<(soldiers[r].second!=-1?to_string(soldiers[r].second):"*")<<ENDL;
            if(soldiers[l].first!=-1){
                soldiers[soldiers[l].first].second=soldiers[r].second;
            }
            if(soldiers[r].second!=-1){
                soldiers[soldiers[r].second].first=soldiers[l].first;
            }
        }
        cout<<"-"<<ENDL;
        
    }

    return 0;
}