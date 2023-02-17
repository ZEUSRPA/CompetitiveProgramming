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
    int t,n,m,d;
    cin>>t;
    while(t--){
        cin>>n>>m>>d;
        vector<int> p(n);
        vector<int> pp(m);
        unordered_map<char,int> pos;
        fore(i,0,n){
            cin>>p[i];
            pos[p[i]]=i;
        }
        fore(i,0,m){
            cin>>pp[i];
        }
        int x=1;
        lli ans = 0;
        while(x<pp.size()){
            lli moves = INT_MAX;
            int l,r,izq,der;
            l=r=izq=der=INT_MAX;
            izq = INT_MIN;
            l=pos[pp[x-1]];
            izq=pos[pp[x-1]]+d+1;
            if(x+1<pp.size()){
                r=pos[pp[x+1]];
                der=pos[pp[x+1]]-d-1;
                if(pos[pp[x-1]]>pos[pp[x+1]]){
                    swap(izq,r);
                    swap(der,l);
                }
                r=max(r,izq);
                l=min(l,der);
            }
            if(l<0){
                l=INT_MAX;
            }
            if(der<0){
                der=INT_MAX;
            }
            if(izq>=p.size()){
                izq=INT_MAX;
            }
            if(r>=p.size()){
                r=INT_MAX;
            }
            lli cu = pos[pp[x]];
            if(pos[pp[x]]<=l || pos[pp[x]]>=r){
                moves=0;
            }else{
                moves = min(moves,abs(cu-l));
                moves = min(moves,abs(cu-r));
                if(izq<=der){
                    moves = min(moves,abs(cu-izq));
                    moves = min(moves,abs(cu-der));
                    if(izq<=cu && cu<=der){
                        moves = 0;
                    }

                }
            }
            ans+=moves;
            x+=2;
        }
        cout<<ans<<ENDL;
    }
    return 0;
}