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
    int t,n,aux;
    cin>>t;
    while(t--){
        cin>>n;
        int maxi=0;
        vector<int> nums(n);
        map<int,pair<int,int>> pos;
        fore(i,0,n){
            cin>>nums[i];
            if(pos.count(nums[i])==0){
                pos[nums[i]]={i,i};
            }else{
                pos[nums[i]].second=i;
            }
            maxi=max(maxi,nums[i]);
        }
        int currentMex=-1;
        fore(i,0,maxi+1){
            if(pos.count(i)==0){
                currentMex=i;
                break;
            }
        }
        if(currentMex==-1){
            currentMex=maxi+1;
        }
        int target=currentMex+1;
        bool answer=true;
        if(target>n){
            answer=false;
        }else{
            bool del=false;
            pair<int,int> attack{-1,-1};
            if(pos.count(target)){
                attack={pos[target].first,pos[target].second};
                del=true;
            }
            if(del){
                map<int,int> count;
                fore(i,0,attack.first){
                    count[nums[i]]++;
                }
                fore(i,attack.second+1,sz(nums)){
                    count[nums[i]]++;
                }
                int fail=0;
                fore(i,0,target){
                    if(count.count(i)==0){
                        fail++;
                    }
                }
                if(fail>1){
                    answer=false;
                }
            }
        }
        cout<<(answer?"Yes":"No")<<ENDL;
    }
    return 0;
}