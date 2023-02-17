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

int const MAXN=1e6;
int const MAXX=1e5+5;

int st[MAXN];
int values[MAXX];

void query(int node, int s, int e,int val){
    if(s==e){
        values[s]-=val;
        st[node]=values[s];
        return;
    }
    int mid=s+(e-s)/2;
    if(st[node*2]>=val){
        query(node*2,s,mid,val);
    }else{
        query(node*2+1,mid+1,e,val);
    }
    st[node]=max(st[node*2],st[node*2+1]);
}

int main() {_ 
    int t,k,n,r,v;
    cin>>t;
    while(t--){
        cin>>k>>n;
        fill(st,st+MAXN-1,k);
        fill(values,values+MAXX-1,k);
        string s;
        while(n--){
            cin>>s;
            if(s[0]=='b'){
                cin>>r>>v;
                n-=r;
                n++;
                while(r--){
                    query(1,1,MAXX-1,v);
                }
            }else{
                v=stoi(s);
                query(1,1,MAXX-1,v);
            }

        }
        int tam=0;
        int ans=0;
        fore(i,1,MAXX){
            if(values[i]!=k){
                ans+=values[i];
                tam++;
            }else{
                break;
            }
        }
        cout<<tam<<" "<<ans<<ENDL;
    }
    return 0;
}