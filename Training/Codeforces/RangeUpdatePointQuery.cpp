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

struct Node{
    lli lazy;
    Node(){
        lazy=0;
    }
};

vector<Node> st;

void update(lli node,lli s, lli e, lli l, lli r){
    if(st[node].lazy!=0){
        if(s!=e){
            st[node*2].lazy+=st[node].lazy;
            st[node*2+1].lazy+=st[node].lazy;
            st[node].lazy=0;
        }
    }
    if(s>r||e<l){
        return;
    }
    if(l<=s && e<=r){
        if(s!=e){
            st[node*2].lazy++;
            st[node*2+1].lazy++;
        }else{
            st[node].lazy++;
        }
        return;
    }
    lli mid=s+(e-s)/2;
    update(node*2,s,mid,l,r);
    update(node*2+1,mid+1,e,l,r);
}

lli query(lli node, lli s, lli e, lli x){
    if(st[node].lazy!=0){
        if(s!=e){
            st[node*2].lazy+=st[node].lazy;
            st[node*2+1].lazy+=st[node].lazy;
            st[node].lazy=0;
        }
    }
    if(s==e){
        lli ans=st[node].lazy;
        st[node].lazy=0;

        return ans;
    }
    lli mid=s+(e-s)/2;
    if(x<=mid){
        return query(node*2,s,mid,x);
    }
    return query(node*2+1,mid+1,e,x);

}

void getAns(vector<string> &nums,lli node, lli times){
    while(times-- && nums[node].size()>1){
       string a=nums[node];
       lli sum=0;
       for(auto x: a){
        sum+=(x-'0');
       }
       a=to_string(sum);
       nums[node]=a;
    }

}

int main() {_ 
    lli t,n,q,x,l,r,node;
    cin>>t;
    while(t--){
        cin>>n>>q;
        vector<string> nums(n+1);
        fore(i,1,n+1){
            cin>>nums[i];
        }
        st=vector<Node> (4*(n+1)+4,Node());
        while(q--){
            cin>>x;
            if(x==1){
                cin>>l>>r;
                update(1,1,n,l,r);
            }else{
                cin>>node;
                lli times = query(1,1,n,node);
                getAns(nums,node,times);
                cout<<nums[node]<<ENDL;

            }
        }

    }
    return 0;
}