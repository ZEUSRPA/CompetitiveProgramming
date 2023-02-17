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
    lli left;
    lli right;
    lli val;
    Node(){
        val=-1;
        left=-1;
        right=-1;
    }
};

vector<Node> tree;
void add(int node, int val){
    if(tree[node].val==-1){
        tree[node].val=val;
        return;
    }
    if(val<tree[node].val){
        if(tree[node].left==-1){
            tree[node].left=tree.size();
            tree.pb(Node());
        }
        add(tree[node].left,val);
    }else{
        if(tree[node].right==-1){
            tree[node].right=tree.size();
            tree.pb(Node());
        }
        add(tree[node].right,val);
    }
}

void preorder(int node,string &s){
    // cout<<tree[node].val<<" ";
    s+=to_string(tree[node].val);
    s+=" ";
    if(tree[node].left!=-1){

        preorder(tree[node].left,s);
    }
    if(tree[node].right!=-1){
        preorder(tree[node].right,s);
    }
}

int main() {_ 
    lli n,x;
    while(cin>>n){
        tree.clear();
        n--;
        tree.pb(Node());
        cin>>x;
        tree[0].val=x;


        while(n--){
            cin>>x;
            add(0,x);

        }
        string s;
        preorder(0,s);
        s.pop_back();
        cout<<s<<ENDL;
    }
    return 0;
}