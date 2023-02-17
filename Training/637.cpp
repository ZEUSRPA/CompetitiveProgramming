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
    while(cin>>n){
        if(n==0){
            break;
        }
        int pa=n/4;
        if(n%4){
            pa++;
        }
        int aux=n%4;
        int p=1,f=n;
        int blanks=pa*4-n;
        int sheet=1;
        cout<<"Printing order for "<<n<<" pages:"<<ENDL;
        if(n==1){
            cout<<"Sheet "<<sheet<<", front: Blank, 1"<<ENDL;
        }else{
            FOR(i,0,pa){
                cout<<"Sheet "<<sheet<<", front: "<<(blanks-->0?"Blank":to_string(f--))<<", "<<p++<<ENDL;
                cout<<"Sheet "<<sheet<<", back : "<<p++<<", "<<(blanks-->0?"Blank":to_string(f--))<<ENDL;
                sheet++;
            }
        }



    }
    return 0;
}