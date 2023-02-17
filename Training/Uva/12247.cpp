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
    int aux;
    while(true){
        int larger=0;
        vector<bool> cards(53,true);
        vector<int> princess;
        vector<int> prince;
        
        FOR(i,0,3){
            cin>>aux;
            princess.pb(aux);
            cards[aux]=false;
            if(aux>larger){
                larger=aux;
            }
        }
        FOR(i,0,2){
            cin>>aux;
            prince.pb(aux);
            cards[aux]=false;
            if(aux>larger){
                larger=aux;
            }
        }
        if(larger==0){
            break;
        }
        sort(princess.begin(),princess.end());
        int wins=0;
        FOR(i,0,2){
            bool z=true;
            FOR(j,0,princess.size()){
                if(princess[j]>prince[i]){
                    princess.erase(princess.begin()+j);
                    z=false;
                    break;
                }
            }
            if(z){
                princess.erase(princess.begin());
                wins++;
            }
        }
        bool si=false;
        int a;
        if(wins>=1){
            if(wins==2){
                a=1;
            }else{
                a=princess[0]+1;
            }
            while(a<53){
                if(cards[a]){
                    cout<<a<<ENDL;
                    si=true;
                    break;
                }
                a++;
            }
            if(!si){
                cout<<-1<<ENDL;
            }
        }else{
            cout<<-1<<ENDL;
        }
    }
    return 0;
}