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
    cin.ignore();
    while(t--){
        int mf=0,mm=0;
        getline(cin,s);
        string aux;
        bool si=false;
        for(auto x:s){
            if(x==' '){
                if(aux=="MM"){
                    mm++;
                    si=true;
                }else if(aux=="MF"||aux=="FM"){
                    mf++;
                }else{
                    si=true;
                    mm--;
                }
                aux.clear();
            }else{
                aux+=x;
            }

        }
        if(aux=="MM"){
            mm++;
            si=true;
        }else if(aux=="MF"||aux=="FM"){
            mf++;
        }else{
            si=true;
            mm--;
        }
        if(mm==0){
            if(si||mf>1){
                cout<<"LOOP"<<ENDL;
            }else{
                cout<<"NO LOOP"<<ENDL;
            }
        }else{
            cout<<"NO LOOP"<<ENDL;
        }

    }
    return 0;
}