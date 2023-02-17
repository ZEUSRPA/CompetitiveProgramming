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
    while(n--){
        unordered_map<int,pair<int,int>> card;
        vector<int> rows(5,0);
        vector<int> colums(5,0);
        vector<int> diagonals(2,0);
        int win=0;
        FOR(i,0,5){
            FOR(j,0,5){
                if(!(i==2 && j==2)){
                    cin>>aux;
                    card[aux]=mp(i,j);
                }
            }
        }
        rows[2]++;
        colums[2]++;
        int r,c;
        FOR(i,0,75){
            cin>>aux;
            if(card.count(aux)){
                rows[card[aux].first]++;
                colums[card[aux].second]++;
                r=0,c=0;
                FOR(j,0,5){
                    if(card[aux].first==r && card[aux].second==c){
                        diagonals[0]++;
                    }
                    r++;
                    c++;
                }
                r=0,c=4;
                FOR(j,0,5){
                    if(card[aux].first==r && card[aux].second==c){
                        diagonals[1]++;
                    }
                    r++;
                    c--;
                }
            }
            if(win==0){
                FOR(j,0,5){
                    if(rows[j]==5 || colums[j]==5){
                        win=i+1;
                    }
                }
                FOR(j,0,2){
                    if(diagonals[j]==4){
                        win=i+1;
                    }
                }

            }
        }
        cout<<"BINGO after "<<win<<" numbers announced"<<ENDL;
    }
    return 0;
}