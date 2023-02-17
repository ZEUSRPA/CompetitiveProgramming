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
vector<int> parent;
vector<int> ranking;

int find(int x){
    if(parent[x]==x){
        return x;
    }
    parent[x]=find(parent[x]);
    return parent[x];
}

void join(int x, int y){
    int px=find(x);
    int py=find(y);
    if(px==py){
        return;
    }
    parent[px]=py;
    ranking[py]+=ranking[px];
    ranking[px]=0;
}


int main() {_ 
    int n,m,k,x;
    cin>>n>>m;
    parent=vector<int>(m+1);
    ranking=vector<int> (m+1,0);
    fore(i,1,m+1){
        parent[i]=i;
    }
    int zero=0;
    fore(i,0,n){
        cin>>k;
        int first=-1;
        if(k==0){
            zero++;
        }
        fore(j,0,k){
            cin>>x;
            if(first==-1){
                first=x;
            }
            ranking[find(x)]++;
            join(first,x);
        }
    }
    set<int> ans;
    
    fore(i,1,m+1){
        int aux=find(i);
        if(ranking[aux]!=0){
            ans.insert(aux);
        }
    }
    int res=ans.size()-1;
    if(res<0){
        res=0;
    }
    res+=zero;
    cout<<res<<ENDL;
    return 0;
}