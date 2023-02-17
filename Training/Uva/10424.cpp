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
    string a,b;
    while(getline(cin,a)){
        getline(cin,b);
        int aa=0,bb=0;
        for(auto &x:a){
            if(isalpha(x)){
                if(isupper(x)){
                    x=tolower(x);
                }
                aa+=x-'a'+1;
            }
        }
        for(auto &x:b){
            if(isalpha(x)){
                if(isupper(x)){
                    x=tolower(x);
                }
                bb+=x-'a'+1;
            }
        }
        while(aa/10>0){
            int aux=0;
            while(aa>0){
                aux+=aa%10;
                aa/=10;
            }
            aa=aux;
        }
        while(bb/10>0){
            int aux=0;
            while(bb>0){
                aux+=bb%10;
                bb/=10;
            }
            bb=aux;
        }
        if(aa>bb){
            aa^=bb;
            bb^=aa;
            aa^=bb;
        }
        cout<<fixed<<setprecision(2)<<float(aa)*100.0/float(bb)<<" %"<<ENDL;
    }

    return 0;
}