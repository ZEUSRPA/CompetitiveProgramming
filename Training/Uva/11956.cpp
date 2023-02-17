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
    int t;
    string s;
    cin>>t;
    FOR(i,1,t+1){
        int p=0;
        vector<int> m(100,0);
        cin>>s;
        for(auto &x:s){
            if(x=='>'){
                p++;
                p%=100;
            }else if(x=='<'){
                p--;
                if(p<0){
                    p+=100;
                }
            }else if(x=='+'){
                m[p]++;
                m[p]%=256;
            }else if(x=='-'){
                m[p]--;
                if(m[p]<0){
                    m[p]+=256;
                }
            }
        }
        cout<<"Case "<<i<<": ";
        char aux[3];
        FOR(j,0,99){
            sprintf(aux,"%X",m[j]);
            if(m[j]<16){
                cout<<"0"<<aux[0]<<" ";
            }else{
                cout<<aux[0]<<aux[1]<<" ";
            }
            
        }
        sprintf(aux,"%X",m[99]);
        if(m[99]<16){
            cout<<"0"<<aux[0]<<ENDL;
        }else{
            cout<<aux[0]<<aux[1]<<ENDL;
        }

    }
    return 0;
}