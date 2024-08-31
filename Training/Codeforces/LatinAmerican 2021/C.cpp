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
    lli n;
    cin>>n;
    vector<lli> glass(n);
    lli tot=0;
    fore(i,0,n){
        cin>>glass[i];
        tot+=glass[i];
    }
    tot = tot/n;
    lli pos = 0;
    lli ans=0;
    lli current=0;
    lli cont=n;
    vector<lli> glass2=glass;
    while(cont){
        ans+=current;
        if(glass[pos]!=-1){
            if(glass[pos]<tot){
                lli aux=min(current,tot-glass[pos]);
                glass[pos]+=aux;
                current-=aux;
                if(glass[pos]==tot){
                    glass[pos]=-1;
                    cont--;
                }
            }else{
                current+=glass[pos]-tot;
                glass[pos]=-1;
                cont--;
            }

        }
        pos++;
        pos%=n;
    }
    cont=n;
    lli ans2=0;
    current=0;
    pos=0;
    while(cont){
        ans2+=current;
        if(glass2[pos]!=-1){
            if(glass2[pos]<tot){
                lli aux=min(current,tot-glass2[pos]);
                glass2[pos]+=aux;
                current-=aux;
                if(glass2[pos]==tot){
                    glass2[pos]=-1;
                    cont--;
                }
            }else{
                current+=glass2[pos]-tot;
                glass2[pos]=-1;
                cont--;
            }

        }
        pos--;
        if(pos<0){
            pos+=n;
        }
    }
    cout<<min(ans,ans2)<<ENDL;
    return 0;
}