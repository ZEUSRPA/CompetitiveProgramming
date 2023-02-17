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

vector<vector<int>> steps;

void bfs(pair<int,int> exitPos,vector<vector<char>> &room){
    queue<pair<int,int>> next;
    next.push(exitPos);
    vector<pair<int,int>> step={{0,-1},{0,1},{-1,0},{1,0}};
    int lvl=0;
    while(!next.empty()){
        int c=next.size();
        while(c--){
            auto aux=next.front();
            next.pop();
            steps[aux.first][aux.second]=lvl;
            for(auto x:step){
                int i=aux.first+x.first;
                int j=aux.second+x.second;
                if(i>=0&&i<steps.size()&&j>=0&&j<steps[0].size()){
                    if(room[i][j]!='#'&&room[i][j]!='X'&&steps[i][j]==-1){
                        next.push({i,j});
                        steps[i][j]=-2;
                    }
                }
            }
        }
        lvl++;
        
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r,c,q,a,b;
    cin>>r>>c;
    vector<vector<char>> room(r,vector<char>(c));
    steps=vector<vector<int>> (r,vector<int>(c,-1));
    pair<int,int> exitPos;
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cin>>room[i][j];
            if(room[i][j]=='E'){
                exitPos={i,j};
            }
        }
    }
    bfs(exitPos,room);
    cin>>q;
    while(q--){
        cin>>a>>b;
        a--;
        b--;
        if(room[a][b]=='E'){
            cout<<'E'<<ENDL;
        }else if(room[a][b]=='X'){
            cout<<'X'<<ENDL;
        }else if(room[a][b]=='#'){
            cout<<'W'<<ENDL;
        }else{
            int current=steps[a][b];
            char response;
            if(steps[a][b]==-1){
                cout<<'?'<<ENDL;
            }else{
                if(b-1>=0&&steps[a][b-1]>=0&&steps[a][b-1]<current){
                    current=steps[a][b-1];
                    response='L';
                }else if(a+1<room.size()&&steps[a+1][b]>=0&&steps[a+1][b]<current){
                    current=steps[a+1][b];
                    response='D';
                }else if(b+1<room[0].size()&&steps[a][b+1]>=0&&steps[a][b+1]<current){
                    current=steps[a][b+1];
                    response='R';
                }else if(a-1>=0&&steps[a-1][b]>=0&&steps[a-1][b]<current){
                    current=steps[a-1][b];
                    response='U';
                }
                cout<<response<<ENDL;
            }
        }
    }
    return 0;
}

