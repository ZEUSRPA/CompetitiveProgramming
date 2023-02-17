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
    int t,n,aux;
    cin>>t;
    while(t--){
        priority_queue<pair<int,int>> maxpq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minpq;
        cin>>n;
        vector<bool> exist(n,true);
        vector<pair<int,int>> res;
        for(int i=0;i<n;i++){
            cin>>aux;
            maxpq.push({aux,i});
            minpq.push({aux,i});
        }
        while(minpq.size()){
            auto mip=minpq.top();
            minpq.pop();
            exist[mip.second]=false;
            auto map=maxpq.top();
            maxpq.pop();
            if(exist[map.second]){
                
                map.first-=mip.first;
                if(map.first>0){
                    maxpq.push(map);
                }
                res.pb({mip.second,map.second});
            }else{
                minpq.push(mip);
            }
        }
        cout<<res.size()<<ENDL;
        for(auto x:res){
            cout<<x.first<<" "<<x.second<<ENDL;
        }
    }
    return 0;
}

