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


vector<int> minOp(string &s,char c){
    vector<int> pos;
    vector<int> res;
    for(int i=0;i<s.size();++i){
        if(s[i]!=c){
            pos.pb(i+1);
        }
    }
    if(pos.size()){
        if(pos.back()==s.size()){
            bool si=false;
            for(int i=ceil(double(s.size()-1)/2.0);i<s.size();i++){
                if(s[i]==c){
                    res.pb(i+1);
                    si=true;
                    break;
                }
            }
            if(!si){
                if(pos.size()>1){
                    res.pb(s.size()-1);
                    res.pb(s.size());
                }else{
                    res.pb(s.size()-1);
                }
            }
        }else{
            res.pb(s.size());
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int n;
    char c;
    string s;
    while(t--){
        cin>>n>>c>>s;
        auto res=minOp(s,c);
        cout<<res.size()<<ENDL;
        if(res.size()){
            for(int i=0;i<res.size()-1;++i){
                cout<<res[i]<<" ";
            }
            cout<<res[res.size()-1]<<ENDL;
            
        }
        
    }
    return 0;
}

