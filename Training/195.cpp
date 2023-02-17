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


unordered_map<char,int> letters;

bool comp(char a,char b){
    return letters[a]<letters[b];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char c='A';
    int a=1;
    while(c<='Z'){
        letters[c]=a;
        a++;
        c=tolower(c);
        letters[c]=a;
        a++;
        c++;
        c=toupper(c);
    }
    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        sort(s.begin(),s.end(),comp);
        cout<<s<<ENDL;
        while(next_permutation(s.begin(),s.end(),comp)){
            cout<<s<<ENDL;
        }
    }
    return 0;
}