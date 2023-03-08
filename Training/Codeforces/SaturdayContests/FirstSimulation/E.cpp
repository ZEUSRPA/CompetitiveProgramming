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


vector<pair<lli,lli>> getList(map<lli,map<lli,pair<lli,lli>>> &g,vector<lli> &bases,lli cont){
    priority_queue<pair<lli,pair<lli,lli>>,vector<pair<lli,pair<lli,lli>>>,greater<pair<lli,pair<lli,lli>>>> nex;
    vector<pair<lli,lli>> ans(cont,{LLONG_MAX,LLONG_MIN});
    fore(i,0,cont){
        if(bases[i]==0){
            nex.push({0,{0,i}});
            ans[i].first=0;
            ans[i].second=0;
        }
    }

    while(nex.size()){
        auto current = nex.top();
        nex.pop();
        if(ans[current.second.second].first==current.first && ans[current.second.second].second==abs(current.second.first)){
                for(auto x:g[current.second.second]){
                    lli cost=current.first+x.second.first;
                    lli prestige = abs(current.second.first)+abs(x.second.second);
                    if(cost<ans[x.first].first){
                        ans[x.first].first=cost;
                        ans[x.first].second=prestige;
                        nex.push({cost,{-prestige,x.first}});
                    }else if(cost==ans[x.first].first){
                        if(prestige>ans[x.first].second){
                            ans[x.first].second=prestige;
                            nex.push({cost,{-prestige,x.first}});

                        }
                    }
                }
        }
    }
    return ans;

}



map<lli,map<lli,pair<lli,lli>>> dp;
// pair<lli,lli> dp[MAXN][MAXN];


pair<lli,lli> getAns(vector<pair<lli,lli>> &list,lli pos,lli b){
    if(pos==list.size()){
        return {0,0};
    }
    if(dp.count(pos)&&dp[pos].count(b)){
        return dp[pos][b];
    }

    pair<lli,lli> ans;
    ans=getAns(list,pos+1,b);
    if(list[pos].second>0){
        if(list[pos].first<=b){
            auto tmp=getAns(list,pos+1,b-list[pos].first);
            tmp.first+=list[pos].first;
            tmp.second+=list[pos].second;
            if(tmp.second>ans.second){
                ans=tmp;
            }else if(tmp.second==ans.second){
                if(tmp.first<ans.first){
                    ans=tmp;
                }
            }
        }
    }
    dp[pos][b]=ans;
    return dp[pos][b];
}

int main() {_ 
    lli b,n,cost,prestige;
    cin>>b>>n;
    string a,y,c;
    map<lli,map<lli,pair<lli,lli>>> g;
    vector<lli> bases(1e4+10,0);
    map<string,lli> aux;
    lli current = 0;
    fore(i,0,n){
        cin>>a>>y>>c>>cost>>prestige;
        if(aux.count(a)==0){
            aux[a]=current++;
        }
        if(aux.count(y)==0){
            aux[y]=current++;
        }
        if(g.count(aux[y])&&g[aux[y]].count(aux[a])){
            if(cost<g[aux[y]][aux[a]].first){
                g[aux[y]][aux[a]]={cost,prestige};
            }else if(cost==g[aux[y]][aux[a]].first){
                if(prestige>g[aux[y]][aux[a]].second){
                    g[aux[y]][aux[a]]={cost,prestige};
                }
            }
        }else{
            g[aux[y]][aux[a]]={cost,prestige};
        }
        bases[aux[a]]++;
    }
    auto values=getList(g,bases,current);
    
    
    auto res=getAns(values,0,b);
    cout<<res.second<<ENDL;
    cout<<res.first<<ENDL;
    return 0;
}