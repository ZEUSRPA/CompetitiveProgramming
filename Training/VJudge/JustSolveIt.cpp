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
vector<int> primes;


void sieve(){
    int siz=1e3+1;
    vector<bool> n(siz,true);
    for(int i=2;i*i<siz;i++){
        if(n[i]){
            for(int j=i*i;j<siz;j+=i){
                n[j]=false;
            }
        }
    }
    FOR(i,2,siz){
        if(n[i]){
            primes.pb(i);
        }
    }
}

void solve(vector<int> &nums){
    unordered_map<int,int> aux;
    
    FOR(i,0,nums.size()){
        int lpf=INT_MAX;
        int gpf=0;
        lli dpf=0;
        lli tpf=0;
        lli nod=1;
        lli sod=1;
        int pos=0;
        while(pos<primes.size()&&nums[i]!=1){
            lli cont=0;
            while(nums[i]%primes[pos]==0){
                cont++;
                nums[i]/=primes[pos];
            }
            if(cont){
                lpf=min(lpf,primes[pos]);
                gpf=max(gpf,primes[pos]);
                dpf++;
                tpf+=cont;
                nod*=cont+1;
                lli cc=0LL;
                lli cv=1LL;
                FOR(j,0,cont+1){
                    cc+=cv;
                    cv*=primes[pos];
                }
                sod*=cc;
            }
            pos++;
        }
        if(nums[i]!=1){
            lpf=min(lpf,nums[i]);
            gpf=max(gpf,nums[i]);
            dpf++;
            tpf++;
            nod*=2;
            lli cc=0LL;
            lli cv=1LL;
            FOR(j,0,2){
                cc+=cv;
                cv*=nums[i];
            }
            sod*=cc;
        }

        cout<<lpf<<" "<<gpf<<" "<<dpf<<" "<<tpf<<" "<<nod<<" "<<sod<<ENDL;

    }
}

int main()
{
    IO;
    sieve();
    int n;
    cin>>n;
    vector<int> nums(n);
    FOR(i,0,n){
        cin>>nums[i];
    }
    solve(nums);

    return 0;
}