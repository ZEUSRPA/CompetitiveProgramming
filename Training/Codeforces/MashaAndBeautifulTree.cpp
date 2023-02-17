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
    int t,m;
    cin>>t;
    while(t--){
        cin>>m;
        vector<int> aux(m);
        FOR(i,0,m){
            cin>>aux[i];
        }
        bool si=true;
        int minop=0;
        for(int i=2;i<=m;i*=2){
            int current=0;
            int pos=i;
            if(si){
                int half=i/2;
                while(pos<=aux.size()){
                    if(aux[pos-half-1]>aux[pos-half]){
                        swap(aux[pos-half],aux[pos-i]);
                        if(i!=2){
                            swap(aux[pos-1],aux[pos-half-1]);
                        }
                        minop++;
                    }
                    if(aux[pos-half]-aux[pos-half-1]!=1){
                        si=false;
                        break;
                    }
                    pos+=i;
                }
            }

        }
        if(si){
            cout<<minop<<ENDL;
        }else{
            cout<<-1<<ENDL;
        }

    }
    return 0;
}