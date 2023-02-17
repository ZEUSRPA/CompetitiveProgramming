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
    lli n,m;
    cin>>n>>m;
    vector<lli> slices(n);
    lli ma=0;
    lli pos=0;
    FOR(i,0,n){
        cin>>slices[i];
        if(slices[i]>ma){
            pos=i;
            ma=slices[i];
        }
    }
    lli diff;
    queue<lli> nex;
    FOR(i,0,n-1){
        diff=abs(slices[i]-slices[i+1]);
        if(diff>m){
            if(slices[i]>slices[i+1]){
                slices[i+1]+=diff-m;
                nex.push(i+1);
            }else{
                slices[i]+=diff-m;
                nex.push(i);
            }
        }
    }
    while(nex.size()){
        int current=nex.front();
        nex.pop();
        if(current-1>=0){
            diff=abs(slices[current]-slices[current-1]);
            if(diff>m){
                if(slices[current]>slices[current-1]){
                    slices[current-1]+=diff-m;
                    nex.push(current-1);
                }else{
                    slices[current]+=diff-m;
                    nex.push(current);
                }
            }
        }
        if(current+1<n){
            diff=abs(slices[current]-slices[current+1]);
            if(diff>m){
                if(slices[current]>slices[current+1]){
                    slices[current+1]+=diff-m;
                    nex.push(current+1);
                }else{
                    slices[current]+=diff-m;
                    nex.push(current);
                }
            }
        }
    }
    FOR(i,0,n){
        cout<<slices[i]<<" ";
    }
    cout<<ENDL;
    return 0;
}