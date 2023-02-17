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

unordered_map<int,int> dp;

int getSegments(vector<int> &segments,int p){
    if(p==segments.size()){
        return 0;
    }
    int res=-1;
    int aux=0;
    if(segments[p]%2){
        if(p<segments.size()-1){
            segments[p]--;
            segments[p+1]++;
            aux=getSegments(segments,p+1);
            if(aux!=-1){
                res=(res==-1)?aux+(segments[p]?1:0):(res,aux+(segments[p]?1:0));
            }
            segments[p]++;
            segments[p+1]--;
            segments[p]++;
            segments[p+1]--;
            aux=getSegments(segments,p+1);
            if(aux!=-1){

                res=(res==-1)?aux+(segments[p]?1:0):min(res,aux+(segments[p]?1:0));
            }
            segments[p]--;
            segments[p+1]++;
        }else{
            res=-1;
        }
    }else{
        aux=getSegments(segments,p+1);
        if(aux!=-1){

            res=(res==-1)?aux+(segments[p]?1:0):min(res,aux+(segments[p]?1:0));
        }
    }
    //dp[p]=res;
    return res;
}

int main(){
    IO;
    int t,n;
    cin>>t;
    string s;
    while(t--){
        cin>>n;
        cin>>s;
        dp.clear();
        int res=0;
        int current=0;
        char curr=s[0];
        int sub=0;
        vector<int> segments;
        for(auto x:s){
            if(x!=curr){
                segments.push_back(current);
                current=1;
                curr=x;
            }else{
                current++;
            }
        }
        curr='x';
        current=0;

        for(auto x:s){
            if(x!=curr){
                if(current%2){
                    current=0;
                    res++;
                }else{
                    current=1;
                }
                curr=x;
            }else{
                current++;
            }
        }
        sub=getSegments(segments,0);
        cout<<res<<" "<<sub<<ENDL;
    }
    return 0;
}