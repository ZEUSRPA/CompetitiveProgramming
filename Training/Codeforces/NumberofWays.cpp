#include <bits/stdc++.h> 
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define mp make_pair
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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> nums(n);
    int sum=0;
    for(int i=0;i<n;++i){
        cin>>nums[i];
        sum+=nums[i];
    }
    if(sum%3==0){
        int aux=sum/3;
        vector<int> cont(3,0);
        for(int i=1;i<n;++i){
            nums[i]+=nums[i-1];
            if(aux==0){
                if(nums[i]==0){
                    
                }
            }else if(nums[i]%aux==0){
                cont[nums[i]/aux-1]++;
            }
        }
        int res=1;
        res*=cont[0]*cont[1];
        cout<<res<<ENDL;
    }else{
        cout<<0<<ENDL;
    }
    return 0;
}

