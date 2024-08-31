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

vector<lli> getSort(vector<vector<int>> &g, vector<lli> &tpsort,vector<lli> &values){
    queue<int> nex;
    vector<lli> answer(tpsort.size(),0);
    fore(i,0,sz(tpsort)){
        if(tpsort[i]==0){
            nex.push(i);
            if(values[i]==0){
                answer[i]=0;
            }else{
                answer[i]=1;
            }
        }
    }
    while(nex.size()){
        int current=nex.front();
        nex.pop();
        for(auto x:g[current]){
            answer[x]=max(answer[x],answer[current]+1);
            tpsort[x]--;
            if(tpsort[x]==0){
                nex.push(x);
            }
        }
    }
    return answer;
}

int main() {_ 
    lli n,b;
    cin>>n>>b;
    vector<lli> values(n);
    fore(i,0,n){
        cin>>values[i];
    }
    vector<vector<int>> g(n);
    vector<lli> tpsort(n,0);
    if(values[0]>values[n-1]){
        g[n-1].pb(0);
        tpsort[0]++;
    }else if(values[n-1]>values[0]){
        g[0].pb(n-1);
        tpsort[n-1]++;
    }
    fore(i,1,n){
        if(values[i]>values[i-1]){
            g[i-1].pb(i);
            tpsort[i]++;
        }else if(values[i-1]>values[i]){
            g[i].pb(i-1);
            tpsort[i-1]++;
        }
    }
    auto ans=getSort(g,tpsort,values);
    fore(i,0,ans.size()-1){
        cout<<ans[i]*b<<" ";
    }
    cout<<ans.back()*b<<ENDL;
    return 0;
}