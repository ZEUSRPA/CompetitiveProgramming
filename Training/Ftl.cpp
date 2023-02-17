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

unordered_map<lli,lli> dp;

lli getAns(lli &p1,lli &t1,lli r1, lli &p2, lli &t2,lli r2,lli h,lli &s, lli current){
    if(dp.count(h)){
        return dp[h];
    }
    if(h<=0){
        return 0;
    }
    lli answer=LLONG_MAX;
    if(r1<=0 && r2<=0){
        answer=min(answer,getAns(p1,t1,t1-min(t1,t2),p2,t2,t2-min(t1,t2),h-(p1+p2-s),s,current+min(t1,t2)));
    }else if(r1<=0){
        answer=min(answer,getAns(p1,t1,t1-min(t1,r2),p2,t2,r2-min(t1,r2),h-(p1-s),s,current+min(t1,r2)));
    }else if(r2<=0){
        answer=min(answer,getAns(p1,t1,t1-min(t2,r1),p2,t2,t2-min(t2,r1),h-(p2-s),s,current+min(t2,r1)));
    }else{
        answer=min(answer,getAns(p1,t1,t1-min(r2,r1),p2,t2,t2-min(r2,r1),h-(r1<r2?p1:p2),s,current+min(r2,r1)));
    }
    answer=min(answer,getAns(p1,t1,r1-max(r2,r1),p2,t2,t2-max(r2,r1),h,s,current+max(r2,r1)));
    dp[h]=answer+current;
    return dp[h];

}

int main()
{
    IO;
    lli p1,p2,t1,t2,h,s;
    cin>>p1>>t1>>p2>>t2>>h>>s;
    cout<<getAns(p1,t1,t1,p2,t2,t2,h,s,0)<<ENDL;

    return 0;
}