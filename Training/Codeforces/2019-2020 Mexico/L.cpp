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

vector<string> board;
vector<vector<lli>> prefix;

bool isPossible(lli mid){
    // deb(mid);
    
    fore(i,1,sz(board[1])-mid+2){
        lli cont=0;
        fore(j,1,sz(board)){
            lli op=abs(prefix[j][i+mid-1]-prefix[j][i-1]);
            // deb(op);
            if(op==mid){
                cont++;
            }else{
                cont=0;
            }
            // deb(cont);
            if(cont==mid){
                return true;
            }
        }
    }
    return false;
}


int main() {_ 
    int n,m;
    cin>>n>>m;
    board.resize(n+1);
    prefix=vector<vector<lli>>(n+1,vector<lli>(m+1,0));
    fore(i,1,n+1){
        cin>>board[i];
        fore(j,0,m){
            if(board[i][j]=='G'){
                prefix[i][j+1]++;
            }else{
                prefix[i][j+1]--;
            }
            prefix[i][j+1]+=prefix[i][j];
            
        }
    }
    lli l=1,r=m+1;
    lli ans=0;
    while(l<=r){
        lli mid=l+(r-l)/2;
        if(isPossible(mid)){
            ans=mid*mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<ENDL;

    return 0;
}