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

int main()
{
    IO;
    int aux;
    vector<int> one,two,three;
    while(cin>>aux){
        if(aux==0)break;
        one.pb(aux);
    }
    while(cin>>aux){
        if(aux==0)break;
        two.pb(aux);
    }
    while(cin>>aux){
        if(aux==0)break;
        three.pb(aux);
    }
    sort(ALLR(one));
    sort(ALLR(two));
    sort(ALLR(three));
    cout<<one.size()<<ENDL;
    for(auto x:one){
        cout<<x<<" ";
    }
    cout<<ENDL;
    cout<<two.size()<<ENDL;
    for(auto x:two){
        cout<<x<<" ";
    }
    cout<<ENDL;
    cout<<three.size()<<ENDL;
    for(auto x:three){
        cout<<x<<" ";
    }
    cout<<ENDL;
    FOR(i,0,one.size()){
        cout<<two[i]-one[i]<<" ";
    }

    
// 100 95 90 88 86 84 82 80 78 76 74 72 70 68 66 64 62 60 58 56 54 52 50 48 46 44 42 40 38 36 34 32 30 28 26 24 22 20 18 16 14 12 10 8 7 6 5 4 3 2 0 
// 150 145 140 135 130 125 120 115 110 105 100 95 90 85 80 75 70 65 63 61 59 57 55 53 51 49 47 45 43 41 39 37 35 33 31 29 27 25 23 21 19 17 15 13 11 9 7 5 3 2 0
// 195 160 190 165 155 140 170 135 150 185 175 180 130 115 80 125 145 90 110 200 120 100 105 70 40 60 65 95 50 85 31 11 7 45 75 17 5 55 13 9 35 15 33 25 29 27 23 19 21 3 0
    return 0;
}