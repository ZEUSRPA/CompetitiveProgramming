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

lli hash_func(const string& s, lli b) {
    static const lli multiplier = 263;
    static const lli prime = 1000000007;
    unsigned long long hash = 0;
    for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
        hash = (hash * multiplier + s[i]) % prime;
    return hash % b;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli m,q,p;
    cin>>m>>q;
    unordered_map<lli,vector<string>> table;
    string aux,s;
    while(q--){
        cin>>aux;
        if(aux=="check"){
            cin>>p;
            for(int i=table[p].size()-1;i>=0;--i){
                cout<<table[p][i]<<" ";
            }
            cout<<ENDL;
        }else{
            cin>>s;
            auto h=hash_func(s,m);
            bool exist=false;
            lli pos=0;
            for(int i=0;i<table[h].size();++i){
                if(table[h][i]==s){
                    exist=true;
                    pos=i;
                    break;
                }
            }
            if(aux=="add"){
                if(!exist){
                    table[h].pb(s);
                }
            }else if(aux=="del"){
                if(exist){
                    table[h].erase(table[h].begin()+pos);
                }
            }else{
                if(exist){
                    cout<<"yes"<<ENDL;
                }else{
                    cout<<"no"<<ENDL;
                }
            }
        }

    }

    return 0;
}

