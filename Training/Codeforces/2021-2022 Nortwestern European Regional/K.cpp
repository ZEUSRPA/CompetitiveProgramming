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

struct Sock{
    int left;
    int right;
    int any;
    Sock(){
        left=0;
        right=0;
        any=0;
    }

};

int main() {_ 
    int n,k;
    cin>>n;
    unordered_map<string,Sock> aux;
    string s,t;
    fore(i,0,n){
        cin>>s>>t>>k;
        if(t=="left"){
            aux[s].left=k;
        }else if(t=="any"){
            aux[s].any=k;
        }else{
            aux[s].right=k;
        }
    }
    int ans=0;
    bool possible =false;
    for(auto x:aux){
        int current = max(x.second.left,x.second.right);
        if(x.second.left>0  && x.second.right>0){
            possible=true;
        }else if(x.second.left>0||x.second.right>0){
            if(x.second.any>0){
                possible=true;
            }
        }else if(x.second.any>=2){
            possible=true;
        }
        if(current==0){
            if(x.second.any>=1){
                current=1;
            }
        }

        ans+=current;
    }
    if(!possible){
        cout<<"impossible"<<ENDL;
    }else{
        ans++;
        cout<<ans<<ENDL;
    }
    return 0;
}