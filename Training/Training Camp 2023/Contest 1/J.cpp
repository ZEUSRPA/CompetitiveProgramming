// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define F first
#define S second
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

int main() {_
    lli n,h;
    cin>>n>>h;
    vector<lli> nums(n);
    lli minpos = 0;
    lli currentmin = INT_MAX;
    fore(i,0,n){
        cin>>nums[i];
        if(nums[i]<currentmin){
            currentmin = nums[i];
            minpos=i;
        }
    }
    if(n==2){
        cout<<0<<ENDL;
        cout<<1<<" "<<1<<ENDL;
    }else{
        sort(all(nums));
        lli minimo = nums[0]+nums[1];
        lli maximo = nums[n-1]+nums[n-2];
        lli diff = maximo-minimo;
        bool two = false;
        lli min2 = min(nums[0]+nums[1]+h,nums[1]+nums[2]);
        lli max2 = max(maximo,nums[n-1]+nums[0]+h);
        if(abs(max2-min2)<diff){
            two = true;
            diff = abs(max2-min2);
        }
        cout<<diff<<ENDL;
        if(two){
            fore(i,0,n){
                if(i==minpos){
                    cout<<2<<" ";
                }else{
                    cout<<1<<" ";
                }
                
            }
            cout<<ENDL;
        }else{
            fore(i,0,n){
                cout<<1<<" ";
            }
            cout<<ENDL;
        }

    }
    return 0;
}