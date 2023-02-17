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
    int a,b,c;

    while(cin>>a>>b>>c){
        vector<int> times;
        if(a==0 &&b==0&&c==0){
            break;
        }
        times.pb(a);
        times.pb(b);
        if(c!=0){
            do{
                times.pb(c);
                cin>>c;
            }while(c!=0);

        }
        sort(times.begin(),times.end());
        vector<int> aux;
        for(auto x:times){
            aux.push_back(x*2);
        }
        int time=0,m=times[0]*2;
        while(time<=18000){
            int r=m;
            time+=m;
            m=200;
            bool si=true;
            FOR(i,0,aux.size()){
                if(time%(times[i]*2)>times[i]-6){
                    si=false;
                }
                aux[i]-=r;
                if(aux[i]==0){
                    aux[i]=times[i]*2;
                }
                if(aux[i]<m){
                    m=aux[i];
                }
            }
            if(si){
                break;
            }
        }
        if(time<=18000){
            int h=time/3600;
            time%=3600;
            int mi=time/60;
            int s=time%60;
            cout<<"0"<<h<<":"<<(mi<10?"0":"")<<mi<<":"<<(s<10?"0":"")<<s<<ENDL;
        }else{
            cout<<"Signals fail to synchronise in 5 hours"<<ENDL;
        }
    }
    return 0;
}