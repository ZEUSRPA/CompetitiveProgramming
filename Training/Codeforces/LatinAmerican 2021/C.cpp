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


int main() {_ 
    lli n;
    cin>>n;
    vector<lli> glass(n);
    lli maxi=0;
    lli pos=0;
    lli sum = 0;
    fore(i,0,n){
        cin>>glass[i];
        if(glass[i]>maxi){
            maxi=glass[i];
            pos=i;
        }
        sum+=glass[i];


    }

    vector<lli> ori=glass;
    
    sum=sum/n;
    // deb(sum);
    vector<lli> pref(n);
    pref[0]=glass[0]-sum;
    maxi = pref[0];
    pos=0;
    fore(i,1,n){
        pref[i]=pref[i-1]+glass[0]-sum;
        if(pref[i]>maxi){
            maxi=pref[i];
            pos=i;
        }
    }
    lli cost=LLONG_MAX;
    lli current = pos;
    lli steps=glass.size();
    lli tot=0;
    lli time=0;
    // while(steps-->0||tot){
    //     cost+=tot;
    //     if(glass[current]>sum){
    //         tot+=glass[current]-sum;
    //     }else if(glass[current]<sum){
            
    //         lli dif = min(tot,sum-glass[current]);
    //         tot-=dif;
    //         glass[current]+=dif;
            
    //     }
    //     current++;
    //     current%=glass.size();
    //     time++;
    // }
    // if(tot||steps>0){
    //     cost=LLONG_MAX;
    // }
    lli cost2=0;
    glass=ori;
    current=pos;
    steps=glass.size();
    time=0;
    tot=0;
    while(steps-->0||tot){
        cost2+=tot;
        if(glass[current]>sum){
            tot+=glass[current]-sum;
        }else if(glass[current]<sum){
            lli dif = min(tot,sum-glass[current]);
            tot-=dif;
            glass[current]+=dif;
           
        }
        current--;
        if(current<0){
            current+=n;
        }
    }
    if(tot||steps>0){
        cost2=LLONG_MAX;
    }
    // deb(cost2);
    cout<<min(cost,cost2)<<ENDL;
    return 0;
}