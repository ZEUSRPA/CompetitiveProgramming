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
    int t;
    cin>>t;
    string s;
    while(t--)
    {
        cin>>s;
        int sum=0;
        for(auto x:s){
            sum+=x-'a'+1;
        }
        string ans="";
        int cont=0;
        if(s.size()%2){
            if(s.size()>1){
                ans="Alice";
                int a=min(s[0]-'a'+1,s.back()-'a'+1);
                cont=(sum-a)-a;
            }else{
                ans="Bob";
                cont=sum;
            }
        }else{
            ans="Alice";
            cont=sum;
        }
        cout<<ans<<" "<<cont<<ENDL;

    }
    return 0;
}