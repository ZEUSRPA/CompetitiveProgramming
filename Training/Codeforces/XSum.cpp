#include <bits/stdc++.h>
#define ENDL '\n'

using namespace std;

int getAns(vector<vector<int>> &board){
    int best=0;
    for(int i=0;i<board.size();++i){
        for(int j=0;j<board[0].size();++j){
            int p=1;
            int current=board[i][j];
            bool other=true;
            while(p<=200&&other){
                other=false;
                if(i+p>=0&&i+p<board.size()&&j+p>=0&&j+p<board[i].size()){
                    current+=board[i+p][j+p];
                    other=true;
                }
                if(i+p>=0&&i+p<board.size()&&j-p>=0&&j-p<board[i].size()){
                    current+=board[i+p][j-p];
                    other=true;
                }
                if(i-p>=0&&i-p<board.size()&&j-p>=0&&j-p<board[i].size()){
                    current+=board[i-p][j-p];
                    other=true;
                }
                if(i-p>=0&&i-p<board.size()&&j+p>=0&&j+p<board[i].size()){
                    current+=board[i-p][j+p];
                    other=true;
                }
                p++;
            }
            best=max(best,current);
        }
    }
    return best;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> board(n,vector<int>(m));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>board[i][j];
            }
        }
        cout<<getAns(board)<<ENDL;
    }
    return 0;
}