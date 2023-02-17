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

bool isFact(unordered_map<string,unordered_map<string,int>>& fact,string a,string b){
    if(a==b){
        return true;
    }
    for(auto x:fact[a]){
        if(isFact(fact,x.F,b)){
            return true;
        }
    }
    return false;
}

bool isAlt(unordered_map<string,unordered_map<string,int>>& alt,string a,string b){
    if(a==b){
        return true;
    }
    for(auto x:alt[a]){
        if(isAlt(alt,x.F,b)){
            return true;
        }
    }
    return false;
}


int main()
{
    IO;
    int n,m;
    cin>>n>>m;
    string a,x,y,z,b;
    unordered_map<string,unordered_map<string,int>> fact;
    unordered_map<string,unordered_map<string,int>> alt;
    for(int i=0;i<n;i++){
        cin>>a>>x>>y>>z>>b;
        fact[a][b]++;
        alt[b][a]++;
    }
    for(int i=0;i<m;++i){
        cin>>a>>x>>y>>z>>b;
        if(isFact(fact,a,b)){
            cout<<"Fact"<<ENDL;
        }else if(isAlt(alt,a,b)){
            cout<<"Alternative Fact"<<ENDL;
        }else{
            cout<<"Pants on Fire"<<ENDL;
        }
    }

    return 0;
}
