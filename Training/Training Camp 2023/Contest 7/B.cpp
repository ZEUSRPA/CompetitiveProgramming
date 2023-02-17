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


bool isValid(vector<ii> &fridge,vector<ii> &store,lli k,lli m){
    lli f=0;
    lli s=store.size()-k;
    lli day=0;
    lli current=m;
    while(f<fridge.size()||s<store.size()){
        if(f<fridge.size()&&s<store.size()){
            // deb(fridge[f].first);
            // deb(store[s].first);
            if(fridge[f]<=store[s]){
                if(fridge[f].first<day){
                    break;
                }
                f++;
            }else{
                if(store[s].first<day){
                    break;
                }
                s++;
            }
        }else if(f<fridge.size()){
            if(fridge[f].first<day){
                break;
            }
            f++;
        }else{
            if(store[s].first<day){
                break;
            }
            s++;
        }
        current--;
        if(current==0){
            day++;
            current=m;
        }
    }

    return (f==fridge.size()&&s==store.size());
}

int main() {_ 
    lli n,m,k;
    cin>>n>>m>>k;
    vector<ii> fridge(n);
    vector<ii> store(m);
    fore(i,0,n){
        cin>>fridge[i].first;
        fridge[i].second=i+1;
    }

    fore(i,0,m){
        cin>>store[i].first;
        store[i].second=i+1;
    }

    sort(ALL(fridge));
    sort(ALL(store));
    lli l=0;
    lli r=store.size();
    lli ans=-1;
    while(l<=r){
        lli mid=l+(r-l)/2;
        if(isValid(fridge,store,mid,k)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<ENDL;
    if(ans!=-1){
        fore(i,m-ans,m){
            cout<<store[i].second<<" ";
        }
        cout<<ENDL;
    }
    return 0;
}