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

bool isPossible(vector<pair<lli,pair<lli,lli>>> &tasks){
    lli last=0;
    fore(i,0,sz(tasks)){
        last+=tasks[i].second.first;
        if(last>tasks[i].first){
            return false;
        }
    }
    return true;
}

vector<lli> getAns(vector<pair<lli,pair<lli,lli>>> &tasks){
    vector<lli> ans;
    vector<bool> visited(sz(tasks)+1,false);
    lli aux=0;
    fore(i,0,sz(tasks)){
        lli best=LLONG_MAX;
        lli add = 0;
        lli auxdd=aux;
        lli mini = LLONG_MAX;
        fore(j,0,sz(tasks)){
            if(visited[tasks[j].second.second])continue;
            lli auxt=tasks[j].first-auxdd-tasks[j].second.first;
            auxdd+=tasks[j].second.first;
            if(tasks[j].second.first<=mini){
                if(tasks[j].second.second<best){
                    best=tasks[j].second.second;
                    add=tasks[j].second.first;
                }
            }
            mini = min(mini,auxt);
        }
        visited[best]=true;
        aux+=add;
        ans.pb(best);
    }
    return ans;
}

int main() {_ 
	lli n;
    cin>>n;
    vector<pair<lli,pair<lli,lli>>> tasks(n);
    fore(i,0,n){
        cin>>tasks[i].second.first>>tasks[i].first;
        tasks[i].second.second=i+1;
    }
    sort(tasks.begin(),tasks.end());
    if(isPossible(tasks)){
        vector<lli> ans = getAns(tasks);
        fore(i,0,sz(ans)-1){
            cout<<ans[i]<<" ";
        }
        cout<<ans.back()<<ENDL;
    }else{
        cout<<"*"<<ENDL;
    }

    return 0;
}
