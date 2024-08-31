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

vector<lli> slices;
vector<lli> parent;
vector<lli> ranking;
vector<pair<lli,lli>> nex;
vector<bool> visited;

lli find(lli x){
    if(parent[x]==x){
        return x;
    }
    parent[x]=find(parent[x]);
    return parent[x];
}

lli join(lli x, lli y){
    visited[x]=true;
    visited[y]=true;
    lli px=find(x);
    lli py=find(y);
    if(px==py){
        return -1;
    }
    nex[py]={nex[px].first,nex[py].second};
    ranking[py]+=ranking[px];
    parent[px]=parent[py];
    return parent[py];
}

void compute(lli x,lli aux){
    lli target = aux+slices[x];
    bool other =true;
    lli current = x;
    while(other){
        other=false;
        if(slices[nex[current].first]<=target){
            lli res = join(nex[current].first,current);
            if(res==-1)break;
            target = ranking[res];
            current=res;
            target+=aux;
            other=true;
        }
        if(slices[nex[current].second]<=target){
            lli res = join(current,nex[current].second);
            if(res==-1)break;
            target=ranking[res];
            target+=aux;
            other=true;
            current=res;
        }
    }
}

bool isPossible(lli aux){
    fore(i,0,sz(slices)){
        visited[i]=false;
        parent[i]=i;
        ranking[i]=slices[i];
        nex[i]={(i-1+sz(slices))%sz(slices),(i+1)%sz(slices)};
    }
    fore(i,0,sz(slices)){
        if(!visited[i]&&slices[i]<=aux){
            compute(i,aux);
        }
    }
    fore(i,0,sz(slices)){
        if(!visited[i]){
            return false;
        }
    }

    
    return true;

}

int main() {_
    int n;
    cin>>n;
    slices.resize(n);
    visited.resize(n);
    parent.resize(n);
    ranking.resize(n);
    nex.resize(n);
    fore(i,0,n){
        cin>>slices[i];
        
    }
    fore(i,0,n){
        parent[i]=i;
        ranking[i]=slices[i];
    }
    lli ans=0;
    lli l=0;
    lli r=1e14;
    while(l<=r){
        lli mid=l+(r-l)/2;
        if(isPossible(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<ENDL;
    return 0;
}