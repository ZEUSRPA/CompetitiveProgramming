// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define F first
#define S second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define ALL(s) begin(s), end(s)
#define ALLR(s) rbegin(s), rend(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;


int main() {_ 
    int  n,m,a,b;
    cin>>n>>m;
    vector<pair<int,int>> beg(n);
    vector<pair<int,int>> fin(n);
    fore(i,0,n){
        cin>>a>>b;
        beg[i].first=a;
        beg[i].second=b;
        fin[i].first=b;
        fin[i].second=a;

    }
    sort(beg.begin(),beg.end());
    sort(fin.rbegin(),fin.rend());
    int l=1;
    int r=m;
    int auxl=fin[0].second;
    int auxr=beg[0].second;
    int pos = 1;
    if(beg[0].first==1){
        l=auxr+1;
        while(pos<n && beg[pos].first<=auxr+1){
            auxr=max(auxr,beg[pos].second);
            l=auxr+1;
            pos++;
        }
    }

    pos=1;
    if(fin[0].first==m){
        r=auxl-1;
        while(pos<n&& fin[pos].first>=auxl-1){
            auxl=min(auxl,fin[pos].second);
            r=auxl-1;
            pos++;
        }
    }
    lli ans = r-l+1;
    if(ans<0){
        ans=0;
    }
    cout<<ans<<ENDL;
    return 0;
}