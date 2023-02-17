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
    string s,t;
    pair<int,int> pos;
    int m=0;
    cin>>s>>t;
    vector<vector<int>> lcs(s.size()+1,vector<int>(t.size()+1,0));
    for(int i=1;i<=s.size();++i){
        for(int j=1;j<=t.size();++j){
            if(s[i-1]==t[j-1]){
                lcs[i][j]=lcs[i-1][j-1]+1;
            }else{
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    string res;
    res.resize(lcs[s.size()][t.size()]);
    int n=res.size()-1;
    int i=s.size();
    int j=t.size();
    while(n>=0){
        if(s[i-1]==t[j-1]){
            res[n]=s[i-1];
            i--;
            j--;
            n--;
        }else if(lcs[i-1][j]>lcs[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    cout<<res<<ENDL;



    return 0;
}

