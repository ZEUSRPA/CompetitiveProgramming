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

vector<int> st;
vector<int> numbers;

void build(int node,int start,int end){
    if(start==end){
        st[node]=numbers[start];
    }else{
        int mid=(start+end)/2;
        build(node*2,start,mid);
        build(node*2+1,mid+1,end);
        st[node]=st[node*2]+st[node*2+1];
    }
}

void update(int node,int start,int end, int idx,int val){
    if(start==end){
        st[node]=val;
        numbers[idx]=val;
    }else{
        int mid=(start+end)/2;
        if(start<=idx && idx<=mid){
            update(node*2,start,mid,idx,val);
        }else{
            update(node*2+1,mid+1,end,idx,val);
        }
        st[node]=st[node*2]+st[node*2+1];
    }
}

int query(int node, int start, int end ,int l ,int r){
    if(r<start || end<l){
        return 0;
    }
    if(l<=start && end<=r){
        return st[node];
    }
    int mid=(start+end)/2;
    return query(node*2,start,mid,l,r)+query(node*2+1,mid+1,end,l,r);

}

int main()
{
    IO;
    int n;
    int c=1;
    while(cin>>n){
        if(n==0){
            break;
        }else{
            if(c!=1){
                cout<<ENDL;

            }
        }
        numbers=vector<int>(n);
        st=vector<int>(4*n+2);
        for(auto &x:numbers){
            cin>>x;
        }
        build(1,0,n-1);
        string s;
        int x,y;
        cout<<"Case "<<c<<":"<<ENDL;
        while(cin>>s){
            if(s=="S"){
                cin>>x>>y;
                update(1,0,n-1,x-1,y);
            }else if(s=="M"){
                cin>>x>>y;
                cout<<query(1,0,n-1,x-1,y-1)<<ENDL;
            }else{
                break;
            }
            
        }
        
        c++;
    }
    return 0;
}