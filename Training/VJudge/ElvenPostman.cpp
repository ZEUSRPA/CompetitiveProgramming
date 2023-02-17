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

struct Node{
    int l;
    int r;
    int v;
    Node(){
        l=-1;
        r=-1;
        v=-1;
    }
};
vector<Node> tree;
void add(int node, int val){
    if(tree[node].v==-1){
        tree[node].v=val;
        return;
    }
    if(val<tree[node].v){
        if(tree[node].l==-1){
            tree[node].l=tree.size();
            tree.pb(Node());
        }
        add(tree[node].l,val);        
    }else{
        if(tree[node].r==-1){
            tree[node].r=tree.size();
            tree.pb(Node());
        }
        add(tree[node].r,val);
    }


}

void find(int node, int val,string &s){
    if(tree[node].v==val){
        return;
    }
    if(val<tree[node].v){
        s+="E";
        find(tree[node].l,val,s);
    }else{
        s+="W";
        find(tree[node].r,val,s);
    }
}

int main() {_ 
    int t,n,x,q;
    cin>>t;
    while(t--){
        tree.clear();
        tree.pb(Node());
        cin>>n;
        fore(i,0,n){
            cin>>x;
            add(0,x);
        }
        cin>>q;
        while(q--){
            string s="";
            cin>>x;
            find(0,x,s);
            cout<<s<<ENDL;
        }
    }   
    return 0;
}