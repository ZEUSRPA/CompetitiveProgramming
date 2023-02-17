#include <bits/stdc++.h>
#define ENDL '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int chips=0;
        vector<string> board(n);
        queue<pair<int,int>> nex;
        for(int i=0;i<n;i++){
            cin>>board[i];
            if(board[i][0]=='*'){
                chips++;
                if(nex.size()==0){
                    nex.push({i,0});
                }
            }
            if(board[i][1]=='*'){
                chips++;
                if(nex.size()==0){
                    nex.push({i,1});
                }
            }
        }
        int lvl=0;
        chips--;
        vector<pair<int,int>> steps{{0,1},{0,-1},{1,0}};
        while(nex.size()){
            int c=nex.size();
            while(c--){
                auto current=nex.front();
                nex.pop();
                if(board[current.first][current.second]=='*'){
                    chips--;
                    board[current.first][current.second]='.';
                    nex = queue<pair<int,int>>();
                    nex.push({current.first,current.second});
                    break;
                }
            }
        }
        cout<<;
    }
    return 0;
}