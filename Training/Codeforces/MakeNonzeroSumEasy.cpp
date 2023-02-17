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

int main()
{
    IO;
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        FOR(i,0,n){
            cin>>nums[i];
        }
        vector<pair<int,int>> ans;
        int last=0;
        FOR(i,1,n){
            if(nums[i]==-1){
                if(i-1>=last&&nums[i-1]==-1){
                    if(ans.size()&&ans[ans.size()-1].second!=i-1){
                        ans.pb({ans[ans.size()].second+1,i-1});
                    }
                    ans.pb({i,i+1});
                    last=i+1;
                }else if(i-1>=last&&nums[i-1]==1&&(i+1==n||nums[i+1]==1)){
                    if(ans.size()&&ans[ans.size()-1].second!=i-1){
                        ans.pb({ans[ans.size()].second+1,i-1});
                    }
                    ans.pb({i,i+1});
                    last=i+1;
                }
            }else{
                if(i-1>=last&&nums[i-1]==-1){
                    if(ans.size()&&ans[ans.size()-1].second!=i-1){
                        ans.pb({ans[ans.size()].second+1,i-1});
                    }
                    ans.pb({i,i+1});
                    last=i+1;
                }
            }
            
        }
        bool si=true;
        if(n==1){
            si=false;
        }else if(ans.size()>0&&ans[ans.size()-1].second!=n){
            if(nums[n-1]==1){
                ans.pb({ans[ans.size()-1].second+1,n});
                
            }else{
                si=false;
            }
        }else{
            if(ans.size()==0){
                if(nums[n-1]==1){
                    ans.pb({1,n});
                   
                }else{
                    si=false;
                }

            }else{
                si=false;
            }
        }

        if(si){
            cout<<ans.size()<<ENDL;
            for(auto x:ans){
                cout<<x.first<<" "<<x.second<<ENDL;
            }
        }else{
            cout<<-1<<ENDL;
        }

    }
    return 0;
}