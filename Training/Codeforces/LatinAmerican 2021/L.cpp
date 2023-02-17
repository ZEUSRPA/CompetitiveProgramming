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

int getAns(vector<pair<int,int>> &times, int s, int x){
    int ans = 0;
    fore(i,0,times.size()){
        if(times[i].second>=s){
            int pos=times[i].first-s;
            if(pos<0){
                pos=s;
            }else{
                if(pos%x){
                    pos=times[i].first+(x-(pos%x));
                }else{
                    pos=times[i].first;
                }
            }
            if(pos<=times[i].second){
                ans++;
                pos=times[i].second-pos;
                ans+=pos/x;
            }

        }
    }
    return ans;
}

int main() {_ 
    int n,x,a,b;
    cin>>n>>x;
    vector<pair<int,int>> times(n);
    fore(i,0,n){
        cin>>a>>b;
        times[i].first=a;
        times[i].second=a+b;
    }
    sort(times.begin(),times.end());
    int current = INT_MAX;
    int best=INT_MAX;
    int btime=8;
    fore(i,0,481){
        current = getAns(times,i,x);
        if(current<best){
            best=current;
            btime=i;
        }
    }
    cout<<btime<<" "<<best<<ENDL;
    return 0;
}