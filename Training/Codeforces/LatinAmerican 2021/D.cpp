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
    lli n,aux;
    cin>>n;
    lli cont=0;
    map<lli,lli> bal;
    priority_queue<lli,vector<lli>,greater<lli>> nex;
    fore(i,0,n){
        cin>>aux;
        nex.push(aux);
        bal[aux]++;
    }
    bool si=false;
    bool correct=false;
    while(nex.size()){
        auto x=nex.top();
        nex.pop();
        

        if(bal[x]>1){
            if(bal.count(x+1)==0){
                nex.push(x+1);
            }
            bal[x+1]+=(bal[x]/2);
            bal[x]=(bal[x]%2);
            si=true;
            
            
        }
        if(bal[x]!=0){
            cont++;
        }

    }
    if(cont==2|| cont==1&&si){
        correct=true;
    }

    cout<<(correct?"Y":"N")<<ENDL;
    return 0;
}