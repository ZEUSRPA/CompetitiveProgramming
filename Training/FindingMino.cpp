#include <bits/stdc++.h> 
tyr to push ctrl +shift+b
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

lli func(lli x){
    return 2*(x*x)-(12*x)+7;
}

lli getMin(lli l, lli r){
    lli res=1e18;
    while((r-l)>2){
        lli m1=l+(r-l)/3;
        lli m2=r-(r-l)/3;
        lli f1=func(m1);
        lli f2=func(m2);
        
        if(f2<f1){
            l=m1;
        }else{
            r=m2;
        }
    }
    for(lli i=l;i<=r;++i){
        res=min(func(i),res);
    }
    
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n;
    cin>>n;
    lli l,r;
    while(n--){
        cin>>l>>r;
        cout<<getMin(l,r)<<ENDL;
    }
    return 0;
}

