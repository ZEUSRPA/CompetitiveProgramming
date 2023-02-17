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
    lli t,n,q;
    cin>>t;
    while(t--){
        cin>>n>>q;
        vector<pair<int,int>> rect(n);
        vector<lli> areas(n);
        vector<lli> areas2(n);
        for(auto &x:rect){
            cin>>x.first>>x.second;
        }
        vector<pair<int,int>> rect2=rect;
        sort(rect.begin(),rect.end(),[](pair<int,int> a,pair<int,int> b){
            if(max(a.first,a.second)>max(b.first,b.second)){
                return false;
            }
            return true;
        });
        sort(rect2.begin(),rect2.end(),[](pair<int,int> a,pair<int,int> b){
            if(min(a.first,a.second)>min(b.first,b.second)){
                return false;
            }
            return true;
        });
        areas[0]=rect[0].first*rect[0].second;
        areas2[0]=rect2[0].first*rect2[0].second;
        for(int i=1;i<n;++i){
            areas[i]=areas[i-1]+rect[i].first*rect[i].second;
            areas2[i]=areas2[i-1]+rect2[i].first*rect2[i].second;
        }
        int hs,ws,hr,wr;

        // for(auto y:rect){
        //     cout<<y.first<<" "<<y.second<<ENDL;
        // }

        while(q--){
            cin>>hs>>ws>>hr>>wr;
            int pos=0;
            for(int p=n;p;p/=2){
                while(pos+p<rect.size()&&max(rect[pos+p].first,rect[pos+p].second)<min(hr,wr)){
                    pos+=p;
                }
            }
            int pos2=0;
            for(int p=n;p;p/=2){
                while(pos2+p<rect.size()&&min(rect[pos2+p].first,rect[pos2+p].second)>max(hs,ws)){
                    pos2+=p;
                }
            }
            if(pos<pos2){
                cout<<areas[pos]<<ENDL;
            }else{
                cout<<areas2[pos2]<<ENDL;
            }

        }


    }
    return 0;
}