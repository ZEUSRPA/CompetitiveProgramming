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

unordered_map<int,unordered_map<int,int>> dp;


int main()
{
    IO;
    int t,n;
    cin>>t;
    string s1,s2;
    while(t--){
        cin>>n>>s1>>s2;
        bool si=true;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='G'){
                s1[i]='B';
            }
            if(s2[i]=='G'){
                s2[i]='B';
            }
            if(s1[i]!=s2[i]){
                si=false;
                break;
            }
        }
        if(si){
            cout<<"YES"<<ENDL;
        }else{
            cout<<"NO"<<ENDL;
        }
    }
    return 0;
}