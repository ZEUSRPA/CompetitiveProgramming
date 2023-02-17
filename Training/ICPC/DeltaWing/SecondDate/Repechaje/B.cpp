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
    cin>>t;
    string s;
    vector<int> aux(6);
    aux[0]=2;
    aux[1]=4;
    aux[2]=3;
    aux[3]=4;
    aux[4]=3;
    aux[5]=4;
    vector<int> ans(6);
    int cas=0;
    while(cas++<t){
        cin>>s;
        int res=0;
        int cont=0;
        int current=0;
        bool as=false;
        for(auto x:s){
            if(x=='*'){
                as=true;
            }else if(x==')'){
                cont++;
                res<<=1;
                if(as){
                    res+=1;
                }
                as=false;
                if(aux[current]==cont){
                    ans[current]=res;
                    cont=0;
                    current++;
                    res=0;
                }
            }
        }
        cout<<"Case "<<cas<<": "<<ans[0]<<ans[1]<<':'<<ans[2]<<ans[3]<<':'<<ans[4]<<ans[5]<<ENDL;

    }
    return 0;
}