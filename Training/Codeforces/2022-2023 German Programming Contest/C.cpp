#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ld long double
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;


//segment tree
struct Node{
    int sum;
    Node(){
        sum=0;
    }
};
vector<Node> st;
void update(int node,int s, int e, int dx, int val){
    if(s==e){
        st[node].sum=val;
        return;
    }
    int mid=s+(e-s)/2;
    if(dx<=mid){
        update(node*2,s,mid,dx,val);
    }else{
        update(node*2+1,mid+1,e,dx,val);
    }
    st[node].sum=st[node*2].sum+st[node*2+1].sum;
}

int query(int node, int s, int e, int l, int r){
    if(s>r || l>e){
        return 0;
    }
    if(s>=l && e<=r){
        return st[node].sum;
    }
    int mid=s+(e-s)/2;
    return query(node*2,s,mid,l,r) + query(node*2+1,mid+1,e,l,r);
}

int main()
{
    IO;
    int n,q,a,b;
    cin>>n>>q;
    char c;
    st=vector<Node> (4*n+4);
    while(q--){
        cin>>c;
        if(c=='?'){
            bool si=false;

            cin>>a>>b;
            if(a>b){
                swap(a,b);
            }
            int one=query(1,1,n,a,b);
            int two=query(1,1,n,1,a)+query(1,1,n,b,n);
            if(one==0 || two==0){
                si=true;
            }
            if(si){
                cout<<"possible"<<ENDL;
            }else{
                cout<<"impossible"<<ENDL;
            }
        }else if(c=='-'){
            cin>>a;
            update(1,1,n,a,1);
        }else{
            cin>>a;
            update(1,1,n,a,0);
        }
    }
    return 0;
}