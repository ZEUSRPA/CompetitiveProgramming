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
    int n,aux;
    cin>>n;
    vector<pair<int,pair<int,int>>> pieces(n);
    vector<pair<int,pair<int,int>>> piecesd(n);

    for(int i=0;i<n;++i){
        cin>>pieces[i].first;
    }
    for(int i=0;i<n;++i){
        cin>>pieces[i].second.first;
        pieces[i].second.second=i+1;
    }
    for(int i=0;i<n;++i){
        cin>>piecesd[i].first;
    }

    for(int i=0;i<n;++i){
        cin>>piecesd[i].second.first;
        piecesd[i].second.second=i+1;
    }
    
    sort(pieces.begin(),pieces.end());
    sort(piecesd.begin(),piecesd.end());

    for(int i=0;i<n-1;++i){
        cout<<pieces[i].second.second<<" ";
    }
    cout<<pieces[n-1].second.second<<ENDL;

    for(int i=0;i<n-1;++i){
        cout<<piecesd[i].second.second<<" ";
    }
    cout<<piecesd[n-1].second.second<<ENDL;

    return 0;
}

