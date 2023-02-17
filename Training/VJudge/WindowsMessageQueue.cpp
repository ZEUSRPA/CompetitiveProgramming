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
#define SZ(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

lli const MAXN=1e5;

int main() {_ 
    string s,x;
    lli a,b;
    lli cont=0;
    vector<pair<string,lli>> messages(MAXN);
    priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>> pq; 
    while(cin>>s){
        if(s=="PUT"){
            cin>>x>>a>>b;
            // deb(b);
            messages[cont]={x,a};
            pq.push({b,cont});
            cont++;
            // deb(pq.size());
        }else{
            // deb(pq.size());
            if(pq.size()){
                auto current=pq.top();
                pq.pop();
                cout<<messages[current.second].first<<" "<<messages[current.second].second<<ENDL;

            }else{
                cout<<"EMPTY QUEUE!"<<ENDL;
            }
        }
    }
    return 0;
}