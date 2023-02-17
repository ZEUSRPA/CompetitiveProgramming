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
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int n,aux;
    cin>>n;
    
    while(n--){
        int md=INT_MAX;
        int l=0,r=1e6;
        int x,r1,r2;
        bool no=true;
        while((r-l)>2){
            int m1=l+(r-l)/3;
            int m2=r-(r-l)/3;
            cout<<m1<<" "<<0<<ENDL;
            cin>>r1;
            if(r1==0){
                no=false;
                break;
            }
            cout<<m2<<" "<<0<<ENDL;
            cin>>r2;
            if(r2==0){
                no=false;
                break;
            }
            if(r2>r1){
                l=r1;
            }else{
                r=r2;
            }
        }
        if(no){
            for(int i=max(0,l-2);i<min(l+2,r+1);++i){
                cout<<i<<" "<<0<<ENDL;
                cin>>aux;
                if(aux==0){
                    no=false;
                    break;
                }
                if(aux<md){
                    md=aux;
                    x=i;
                }
            }
        }
        
        if(no){
            while((r-l)>2){
                int m1=l+(r-l)/3;
                int m2=r-(r-l)/3;
                cout<<x<<" "<<m1<<ENDL;
                cin>>r1;
                if(r1==0){
                    no=false;
                    break;
                }
                cout<<x<<" "<<m2<<ENDL;
                cin>>r2;
                if(r2==0){
                    no=false;
                    break;
                }
                if(r2>r1){
                    l=r1;
                }else{
                    r=r2;
                }
            }
        }
        
        if(no){
            for(int i=max(0,l-2);i<min(l+2,r+1);++i){
                cout<<x<<" "<<i<<ENDL;
                cin>>aux;
                if(aux==0){
                    no=false;
                    break;
                }
            }
            
        }



    }

    return 0;
}

