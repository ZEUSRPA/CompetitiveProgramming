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
    int n,c,b,aux;
    cin>>n>>c>>b;
    vector<int> bt(b);
    FOR(i,0,b){
        cin>>bt[i];
        bt[i]--;
    }
    reverse(bt.begin(),bt.end());
    string res="";
    FOR(i,0,n){
        res+='0';
    }
    int pos=1;
    
    int current=0;
    FORN(i,n-1,1){
        if(pos<bt.size()&&i==bt[pos]){
            if(res[i+1]=='1'){
                current++;
            }
            pos++;
            continue;
        }
        if(res[i+1]=='0'){
            if(current<c-1){
                current++;
                res[i]='1';
            }
        }else{
            current++;
        }
        
    }
    if(current<c){
        res[0]=res[1]=='0'?'1':'0';
    }
    cout<<res<<ENDL;
    return 0;
}