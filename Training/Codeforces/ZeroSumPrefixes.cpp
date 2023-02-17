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
        vector<lli> nums(n);
        vector<lli> prefix(n);
        vector<pair<lli,lli>> similar(n);
        vector<lli> similar2(n);
        int totalzero=0;
        cin>>nums[0];
        prefix[0]=nums[0];
        if(prefix[0]==0){
            totalzero++;
        }
        FOR(i,1,n){
            cin>>nums[i];
            prefix[i]=prefix[i-1]+nums[i];
            // cout<<prefix[i]<<" ";
            if(prefix[i]==0){
                totalzero++;
            }
        }
        // cout<<ENDL;
        unordered_map<lli,lli> aux;
        unordered_map<lli,lli> aux2;
        aux[prefix[n-1]]++;
        similar[n-1].first=1;
        similar[n-1].second=prefix[n-1];
        FORN(i,n-1,0){
            aux[prefix[i]]++;
            if(similar[i+1].first>aux[prefix[i]]){
                similar[i].first=similar[i+1].first;
                similar[i].second=similar[i+1].second;
            }else{
                similar[i].first=aux[prefix[i]];
                similar[i].second=prefix[i];
            }
            
        }
        // aux2[prefix[0]]++;
        // similar2[0]=1;
        // FOR(i,1,n){
        //     aux2[prefix[i]]++;
        //     similar[i].first=max(similar[i-1].first,aux2[prefix[i]]);
        // }
        int res=0;
        int totalzeror=0;
        lli change=0;
        FOR(i,0,n){
            if(nums[i]==0){
                if(similar[i].first>totalzero){
                    //cout<<'k'<<similar[i].first<<ENDL;
                    totalzero=similar[i].first;
                    change-=(similar[i].second+change);
                    if(prefix[i]+change==0){
                        res++;
                        totalzero--;
                    }
                }else if(1>totalzero){
                    totalzero=0;
                    change-=(prefix[i]+change);
                    res++;
                    
                }else if(prefix[i]+change==0){
                    res++;
                    totalzero--;
                }
            }else if(prefix[i]+change==0){
                res++;
                totalzero--;
            }
        }
        cout<<res<<ENDL;
    }
    return 0;
}