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
    string s;
    while(getline(cin,s)){
        
        if(s=="Game Over"){
            break;
        }
        int finalscore=0;
        vector<char> points;
        int cont=0;
        int aux=0;
        for(auto x:s){
            if(x!=' '){
                points.pb(x);
            }
        }
        bool wait=false;
        FOR(i,0,points.size()){
            if(cont==10){
                break;
            }
            if(points[i]=='X'){
                finalscore+=10;
                cont++;
                if(points[i+1]=='X'){
                    finalscore+=10;
                    if(points[i+2]=='X'){
                        finalscore+=10;
                    }else{
                        finalscore+=points[i+2]-'0';
                    }
                }else{
                    if(points[i+2]=='/'){
                        finalscore+=10;
                    }else{
                        finalscore+=points[i+1]-'0'+points[i+2]-'0';
                    }
                }
            }else if(points[i]=='/'){
                cont++;
                finalscore+=10;
                if(points[i+1]=='X'){
                    finalscore+=10;
                }else{
                    finalscore+=points[i+1]-'0';
                }
                wait=false;
                aux=0;
            }else{
                aux+=points[i]-'0';
                if(wait){
                    cont++;
                    finalscore+=aux;
                    aux=0;
                    wait=false;
                }else{
                    wait=true;
                }
                
            }
        }
        cout<<finalscore<<ENDL;


        
    }
    return 0;
}