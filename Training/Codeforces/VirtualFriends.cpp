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

unordered_map<string,string> relations;
unordered_map<string,int> ranking;

string find(string a){
    if(relations[a]==a){
        return a;
    }
    relations[a]=find(relations[a]);
    return relations[a];
}

int unir(string a,string b ){
    string pa=find(a);
    string ppb=find(b);
    if(pa==ppb){
        return ranking[pa];
    }
    relations[pa]=ppb;
    ranking[ppb]+=ranking[pa];
    return ranking[ppb];
} 

int main()
{
    IO;
    int t,f;
    cin>>t;
    string a,b;
    while(t--){
        relations.clear();
        ranking.clear();

        cin>>f;
        FOR(i,0,f){
            cin>>a>>b;
            if(relations.count(a)==0){
                relations[a]=a;
                ranking[a]=1;
            }
            if(relations.count(b)==0){
                relations[b]=b;
                ranking[b]=1;
            }
            cout<<unir(a,b)<<ENDL;
        }
    }
    return 0;
}