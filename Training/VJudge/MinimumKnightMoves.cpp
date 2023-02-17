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

int moves(string s,string d){
    vector<vector<int>> board(8,vector<int>(8,-1));
    queue<pair<int,int>> nex;
    nex.push({s[0]-'a',s[1]-'1'});
    board[s[0]-'a'][s[1]-'1']=1;
    int move=0;
    vector<pair<int,int>> steps={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};

    while(nex.size()){
        int c=nex.size();
        while(c--){
            auto current=nex.front();
            nex.pop();
            if(current.first==d[0]-'a'&&current.second==d[1]-'1')
                return move;
            for(auto x:steps){
                int a=current.first+x.first;
                int b=current.second+x.second;
                if(a>=0&&a<board.size()&&b>=0&&b<board[0].size()&&board[a][b]==-1){
                    board[a][b]=1;
                    nex.push({a,b});
                }
            }
        }
        move++;
    }
    return move;
}

int main()
{
    IO;
    int t;
    cin>>t;
    string s,d;
    while(t--){
        cin>>s>>d;
        cout<<moves(s,d)<<ENDL;
    }
    return 0;
}