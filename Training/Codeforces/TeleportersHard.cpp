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
    lli t,n,c;
    cin>>t;
    while(t--){
        cin>>n>>c;
        vector<lli> costs(n);
        priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>> > nex;
        fore(i,0,n){
            cin>>costs[i];
            nex.push({costs[i]+i+1,i});
        }
        vector<bool> visited(n,false);
        pair<lli,lli> current = nex.top();
        nex.pop();
        lli ans=0;
        if(current.first<=c){
            ans++;
            visited[current.second]=true;
            c-=current.first;
        }

        fore(i,0,n){
            nex.push({costs[i]+n-i,i});
        }

        while(nex.size()){
            current=nex.top();
            nex.pop();
            if(!visited[current.second]){
                if(current.first<=c){
                    ans++;
                    visited[current.second]=true;
                    c-=current.first;
                }else{
                    break;
                }
            }
        }
        cout<<ans<<ENDL;


    }
    return 0;
}