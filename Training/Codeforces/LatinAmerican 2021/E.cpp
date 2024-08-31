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

lli const MAXN=4e5+100;
struct Node{
    lli val;
    lli left;
    lli right;
    lli lazy;
    Node(){
        val=0;
        lazy=0;
        left=-1;
        right=-1;
    }
};

Node st[MAXN];

void push(int node){
    st[node*2].lazy+=st[node].lazy;
    st[node*2+1].lazy+=st[node].lazy;
    if(st[node].left!=-1){
        st[node*2].left=st[node].left;
        st[node*2+1].left=st[node].left;
    }
    if(st[node].right!=-1){
        st[node*2].right=st[node].right;
        st[node*2+1].right=st[node].right;
    }
    st[node].left=-1;
    st[node].right=-1;
    st[node].lazy=0;
}

void update(int node, int s, int e, int l, int r, int current, bool left,int sum){
    
    if(st[node].lazy||st[node].left!=-1||st[node].right!=-1){
        if(s!=e){
            push(node);
        }else{
            st[node].val+=st[node].lazy;
            st[node].lazy=0;
        }
    }
    if(e<l||s>r){
        return;
    }
    if(l<=s && e<=r){
        if(left){
            st[node].left=current;
        }else{
            st[node].right=current;
        }
        if(s!=e){
            st[node].lazy+=sum;
            push(node);
        }else{
            st[node].val+=sum;
        }
    }else{
        int mid=s+(e-s)/2;
        update(node*2,s,mid,l,r,current,left,sum);
        update(node*2+1,mid+1,e,l,r,current,left,sum);
    }
}

Node query(int node, int s, int e, int dx){
    if(st[node].lazy||st[node].left!=-1||st[node].right!=-1){
        if(s!=e){
            push(node);
        }else{
            st[node].val+=st[node].lazy;
            st[node].lazy=0;
        }
    }
    if(s==e){
        return st[node];
    }
    int mid=s+(e-s)/2;
    if(dx<=mid){
        return query(node*2,s,mid,dx);
    }
    return query(node*2+1,mid+1,e,dx);
}


int main() {_ 
    int n;
    cin>>n;
    vector<lli> height(n);
    priority_queue<pair<lli,lli>> nex;
    fore(i,0,n){
        cin>>height[i];
        nex.push({height[i],i});
    }
    while(nex.size()){
        auto current = nex.top();
        nex.pop();
        auto x=query(1,0,n-1,current.second);
        // deb(current.second);
        // deb(x.left);
        // deb(x.right);
        if(x.left==-1){
            update(1,0,n-1,0,current.second-1,current.second,false,1);
        }else{
            lli start=current.second-(current.second-x.left)/2;
            if((current.second-x.left)%2==0){
                start++;
            }
            if(start<=current.second-1){
                update(1,0,n-1,start,current.second-1,current.second,false,1);
            }
            update(1,0,n-1,x.left,current.second,current.second,false,0);
        }
        if(x.right==-1){
            update(1,0,n-1,current.second+1,n-1,current.second,true,1);
        }else{
            lli start=current.second+(x.right-current.second)/2;
            if((x.right-current.second)%2==0){
                start--;
            }
            if(start>=current.second+1){
                update(1,0,n-1,current.second+1,start,current.second,true,1);
            }
            update(1,0,n-1,current.second,x.right,current.second,true,0);
        }
    }
    fore(i,0,n-1){
        cout<<query(1,0,n-1,i).val<<" ";
    }
    cout<<query(1,0,n-1,n-1).val<<ENDL;
    return 0;
}