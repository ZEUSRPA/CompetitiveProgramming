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
    int n;
    cin>>n;
    vector<int > nums(n);
    for(auto &x:nums){
        cin>>x;
    }
    sort(nums.begin(),nums.end());
    int current=nums.size();
    int cont=0;
    int prev=nums[0];
    long long int ans=0;
    for(auto x:nums){
        if(x==prev){
            cont++;
        }else{
            ans+=current;
            current-=cont;
            cont=1;
            prev=x;
        }
    }
    ans+=current;
    cout<<ans<<ENDL;
    return 0;
}