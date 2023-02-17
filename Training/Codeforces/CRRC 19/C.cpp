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


void solve(string s){
    unordered_map<char,int> aux;
    auto reduce = [&](string w){
        for(auto y:w){
            aux[y]--;
        }
    };
    for(auto x:s){
        aux[x]++;
    }
    string show;
    while(aux['[']){
        show="[:|||:]";
        cout<<show<<ENDL;
        reduce(show);
    }
    while(aux['~']){
        show=":~(";
        cout<<show<<ENDL;
        reduce(show);
    }
    while(aux['X']){
        show=":-X";
        cout<<show<<ENDL;
        reduce(show);
    }
    while(aux['%']){
        show="%0";
        cout<<show<<ENDL;
        reduce(show);
    }
    while(aux['E']){
        show=":-E";
        cout<<show<<ENDL;
        reduce(show);
    }
    while(aux['8']){
        show="8-0";
        cout<<show<<ENDL;
        reduce(show);
    }
    while(aux['|']){
        show=":-|";
        cout<<show<<ENDL;
        reduce(show);
    }
    while(aux['0']){
        show=":-0";
        cout<<show<<ENDL;
        reduce(show);
    }
    while(aux['C']){
        show=":C";
        cout<<show<<ENDL;
        reduce(show);
    }
    while(aux['D']){
        show=":D";
        cout<<show<<ENDL;
        reduce(show);
    }
    while(aux['P']){
        show=":-P";
        cout<<show<<ENDL;
        reduce(show);
    }
    while(aux['\\']){
        show=":-\\";
        cout<<show<<ENDL;
        reduce(show);
    }
    while(aux[':']&&aux['(']){
        show=":(";
        cout<<show<<ENDL;
        reduce(show);
    }
    while(aux[':']&&aux[')']){
        show=":)";
        cout<<show<<ENDL;
        reduce(show);
    }
    while(aux['(']){
        show=";-(";
        cout<<show<<ENDL;
        reduce(show);
    }
    while(aux[')']){
        show=";-)";
        cout<<show<<ENDL;
        reduce(show);
    }
    cout<<"LOL"<<ENDL;
}

int main()
{
    IO;
    string s;
    cin>>s;
    solve(s);
    return 0;
}
