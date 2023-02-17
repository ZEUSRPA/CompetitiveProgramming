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

bool isFree(vector<vector<int>>& board,int x, int y){
    for(int i=0;i<board.size();++i){
        if(board[x][i]==1){
            return false;
        }
        if(board[i][y]==1){
            return false;
        }
    }
    vector<pair<int,int>> s={{1,1},{1,-1},{-1,1},{-1,-1}};
    int aux=1;
    bool other=true;
    while(other){
        other=false;
        for(auto z:s){
            int a=x+(aux*z.first);
            int b=y+(aux*z.second);
            if(a>=0&&a<board.size()&&b>=0&&b<board.size()){
                if(board[a][b]==1){
                    return false;
                }else{
                    other=true;
                }
            }
        }
        aux++;
    }
    return true;
}


bool place(vector<vector<int>>& board,int queens){
    if(queens==0){
        return true;
    }
    for(int i=0;i<board.size();++i){
        for(int j=0;j<board.size();++j){
            if(board[i][j]==0){
                if(isFree(board,i,j)){
                    board[i][j]=1;
                    if(place(board,queens-1)){
                        return true;
                    }else{
                        board[i][j]=0;
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n,0));
    if(place(board,n)){
        cout<<"YES"<<ENDL;
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;++j){
                cout<<board[i][j]<<" ";
            }
            cout<<board[i][n-1]<<ENDL;
        }
    }else{
        cout<<"NO"<<ENDL;
    }
    return 0;
}

