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
    int n;
    cin>>n;
    string a,b,c;
    while(n--){
        unordered_map<char,int> good;
        unordered_map<char,int> bad;
        unordered_map<char,int> cont;
        int z=0;
        FOR(i,0,3){
            cin>>a>>b>>c;
            if(c=="even"){
                FOR(k,0,a.size()){
                    good[a[k]]=1;
                    good[b[k]]=1;
                }
            }else if(c=="up"){
                FOR(k,0,a.size()){
                    bad[a[k]]++;
                    bad[b[k]]--;
                    cont[a[k]]++;
                    cont[b[k]]++;
                }
                z++;
            }else{
                FOR(k,0,a.size()){
                    bad[a[k]]--;
                    bad[b[k]]++;
                    cont[a[k]]++;
                    cont[b[k]]++;
                }
                z++;
            }
            
        }
        for(auto x:bad){
            if(cont[x.first]==z&&z==abs(x.second)&&good.count(x.first)==0){
                if(x.second<0){
                    cout<<x.first<<" is the counterfeit coin and it is light."<<ENDL;
                }else{
                    cout<<x.first<<" is the counterfeit coin and it is heavy."<<ENDL;
                }
                break;
            }
        }

    }
    return 0;
}