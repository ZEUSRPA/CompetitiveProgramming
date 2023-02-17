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

int join(int x, int y){
    int px=find(x);
    int py=find(y);
    if(px==py){
        return ranking[py];
    }
    parent[px]=py;
    ranking[py]+=ranking[px];
    ranking[px]=0;
    return ranking[py];
}



int main() {_ 
    int t,k;
    cin>>t;
    string a,b;
    while(t--){
        map<string,int> aux;
        vector<pair<int,int>> connections;
        cin>>k;
        int count=1;
        fore(i,0,k){
            cin>>a>>b;
            if(aux.count(a)==0){
                aux[a]=count;
                count++;
            }
            if(aux.count(b)==0){
                aux[b]=count;
                count++;
            }
            connections.pb({aux[a],aux[b]});
        }
        parent=vector<int> (count);
        ranking=vector<int>(count,1);
        fore(i,1,count){
            parent[i]=i;
        }
        for(auto x:connections){
            cout<<join(x.first,x.second)<<ENDL;1
        }

    }
    return 0;
}