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

struct Node{
    int val;
    int depth;
    Node(){
        val=0;
        depth=0;
    }

};

vector<Node> st;

vector<int> nums;

void build(int node, int s, int e){
    if(s==e){
        st[node].val=nums[e];
        st[node].depth=0;
        return;
    }
    int mid=s+(e-s)/2;
    build(node*2,s,mid);
    build(node*2+1,mid+1,e);
    st[node].depth=st[node*2].depth+1;
    if(st[node].depth%2==1){
        st[node].val=st[node*2].val|st[node*2+1].val;
    }else{
        st[node].val=st[node*2].val^st[node*2+1].val;
    }

}

int update(int node, int s, int e, int pos, int value){
    if(s==e && s==pos){
        nums[pos]=value;
        st[node].val=value;
        return st[node].val;
    }
    int mid=s+(e-s)/2;
    if(pos<=mid){
        update(node*2,s,mid,pos,value);
    }else{
        update(node*2+1,mid+1,e,pos,value);
    }
    if(st[node].depth%2==1){
        st[node].val=st[node*2].val|st[node*2+1].val;
    }else{
        st[node].val=st[node*2].val^st[node*2+1].val;
    }
    return st[node].val;
}




int main()
{
    IO;
    int n,m,a,b;
    cin>>n>>m;
    n=(1<<n);
    st=vector<Node> (n*4+4);
    nums=vector<int> (n+1);
    FOR(i,1,n+1){
        cin>>nums[i];
    }
    build(1,1,n);
    while(m--){
        cin>>a>>b;
        cout<<update(1,1,n,a,b)<<ENDL;

    }
    return 0;
}