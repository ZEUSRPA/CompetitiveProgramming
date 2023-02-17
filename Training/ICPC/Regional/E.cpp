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
    int n,t,m=0,pos;
    cin>>n;
    vector<int> h(n);
    for(int i=0;i<n;++i){
        cin>>h[i];
        if(h[i]>m){
            m=h[i];
            pos=i;
        }
    }
    vector<int> res(n,0);

    int cur=0;
    for(int i=pos+1;i<n-1;++i){
        if(h[i-1]>h[i]||h[i+1]>h[i]){
            cur++;
        }else{
            cur--;
        }
        res[i]=cur;
    }
    if(h[n-2]>h[n-1]){
        cur++;
    }else{
        cur--;
    }
    res[n-1]=cur;
    cur=0;
    for(int i=pos-1;i>0;--i){
        if(h[i-1]>h[i]||h[i+1]>h[i]){
            cur++;
        }else{
            cur--;
        }
        res[i]=cur;
    }
    if(h[1]>h[0]){
        cur++;
    }else{
        cur--;
    }
    res[0]=cur;
    for(int i=0;i<n-1;++i){
        cout<<res[i]<<" ";
    }
    cout<<res[n-1]<<ENDL;
    return 0;
}

