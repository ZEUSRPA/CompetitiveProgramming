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
    int n,d;
    cin>>n>>d;
    vector<pair<int,int>> nums(n);
    map<int,map<int,int>> valid;
    fore(i,0,n){
        cin>>nums[i].first;
        nums[i].second=i%d;
    }
    sort(nums.begin(),nums.end());
    bool si=true;
    fore(i,0,n){
        valid[nums[i].first][i%d]++;
    }
    fore(i,0,n){
        if(valid[nums[i].first][nums[i].second]>0){
            valid[nums[i].first][nums[i].second]--;
        }else{
            si=false;
            break;
        }
    }
    cout<<(si?"YES":"NO")<<ENDL;
    return 0;
}