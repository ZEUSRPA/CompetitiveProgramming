// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define f first
#define s second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
#define deb(x) cout << #x": " << (x) << endl;

int find(vector<int> &parent, int a){
    if(parent[a]==a){
        return a;
    }
    parent[a]=find(parent,parent[a]);
    return parent[a];
}

void set_union(vector<int> &parent,int a, int b){
    int pa=find(parent,a);
    int pbb=find(parent,b);
    if(pa==pbb){
        return;
    }else{
        parent[pa]=pbb;
    }
}

void palindrome(vector<int> &parent, vector<bool> &known,int l, int r){
    while(l<r){
        known[l]=true;
        known[r]=true;
        set_union(parent,l,r);
        l++;
        r--;
    }
}

int isEqual(vector<int> &parent, vector<bool> &known, int a, int b, int x ,int y){
    if(b-a!=y-x){
        return -1; 
    }
    int ans=1;
    while(a<=b){
        if(!known[a]||!known[x]){
            ans=0;
        }else{
            int pa=find(parent,a);
            int pbb=find(parent,x);
            if(pa!=pbb){
                return -1;
            }
        }
        a++;
        x++;
    }
    return ans;
}

int main(){ _
    int n,q,opt,l,r,a,b,x,y;
    cin>>n>>q;
    vector<int> parent(n+1);
    vector<bool> known(n+1,false);
    fore(i,0,n+1){
        parent[i]=i;
    }
    while(q--){
        cin>>opt;
        if(opt==1){
            cin>>l>>r;
        }else{
            cin>>a>>b>>x>>y;
        }
    }
    return 0;
}