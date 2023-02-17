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
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    unordered_map<char,int> a;
    unordered_map<char,int> b;
    for(auto x:s1){
        if(x==' '){
            a['*']++;
        }
        a[x]++;
    }
    for(auto x:s2){
        if(x==' '){
            b['*']++;
        }
        b[x]++;
    }
    for(auto x:b){
        if(a[x.first]<x.second){
            if(x.first=='*'){
                cout<<' ';
            }else{

                cout<<x.first;
            }
        }
    }
    cout<<ENDL;

    return 0;
}

