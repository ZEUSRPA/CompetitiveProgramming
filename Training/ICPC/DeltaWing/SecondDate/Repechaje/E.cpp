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

lli largets(lli n){
    int aux=0;
    while(n!=0){
        n>>=1;
        aux++;
    }

    return 1<<(aux-1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n,m,cont=1;
    char c;
    while(cin>>n){
        if(n==-1){
            break;
        }
        cin>>m>>c;
        vector<lli> ans;
        int aa=n;
        if(n==0||m==0){
            cout<<"Case "<<cont<<": "<<aa<<" x "<<m<<" = "<<0<<ENDL;
            cont++;
            continue;
        }
        while(n!=0){
           lli x= largets(n);
           ans.pb(x*m);
           n-=x;
        }
        if(c=='u'){
            reverse(ans.begin(),ans.end());
        }
        cout<<"Case "<<cont<<": "<<aa<<" x "<<m<<" = "<<ans[0];

        FOR(i,1,ans.size()){
            cout<<" + "<<ans[i];
        }
        cout<<ENDL;
        cont++;
    }
    
    return 0;
}