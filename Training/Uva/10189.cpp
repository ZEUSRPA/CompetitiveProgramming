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
    int n,m;
    char c;
    int z=1;
    while(cin>>n>>m){
        
        unordered_map<int,unordered_map<int,int>> board;
        unordered_map<int,unordered_map<int,bool>> mines;

        if(n==0 && m==0){
            break;
        }
        if(z>1){
            cout<<ENDL;
        }
        FOR(i,0,n){
            FOR(j,0,m){
                cin>>c;
                if(c=='*'){
                    mines[i][j]=true;
                    board[i+1][j]++;
                    board[i+1][j+1]++;
                    board[i+1][j-1]++;
                    board[i][j+1]++;
                    board[i][j-1]++;
                    board[i-1][j]++;
                    board[i-1][j-1]++;
                    board[i-1][j+1]++;
                }
            }
        }
        cout<<"Field #"<<z++<<":"<<ENDL;
        FOR(i,0,n){
            FOR(j,0,m){
                if(mines[i][j]){
                    cout<<"*";
                }else{
                    cout<<board[i][j];
                }
            }
            cout<<ENDL;
        }
    }
    return 0;
}