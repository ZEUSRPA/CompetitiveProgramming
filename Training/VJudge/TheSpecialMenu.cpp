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

map<string,int> dp;
map<pair<string,int>, int> dup;

bool isP(string &s){
    int l=0,r=s.size()-1;
    while(l<r){
        if(s[l++]!=s[r--]){
            return false;
        }
    }
    // if(dup.count(s)){
    //     return false;
    // }
    // dup[s]++;
    return true;
}

int cont;

int countP(string &s){
    int res=0;
    for(int i=0;i<(1<<s.size());++i){
        string aux="";
        for(int j=0;j<s.size();j++){
            if(i&(1<<j)){
                aux.pb(s[j]);
            }
        }
        if(isP(aux)){
            res++;
        }
    }
    return --res;
}
void doit(string &s){
    if(s.size()==0){
        return;
    }
    if(dp.count(s)){
        return;
    }
    
    for(int i=0;i<s.size();++i){
        string aux=s;
        aux.erase(aux.begin()+i);
        doit(aux);
    }
    if(isP(s)){
        cont++;
    }
    dp[s]=cont;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int c=0;
    string s;
    while(c++<t){
        cont=0;
        cin>>s;
        cout<<"Case "<<c<<": "<<countP(s)<<ENDL;
    }
    return 0;
}