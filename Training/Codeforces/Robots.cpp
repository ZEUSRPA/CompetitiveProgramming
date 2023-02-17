#include <bits/stdc++.h>
#define ENDL '\n'

using namespace std;

bool isPossible(vector<pair<int,int>> &robots,int n, int m){
    for(int i=0;i<robots.size();++i){
        int a=robots[i].first;
        int b=robots[i].second;
        bool si=true;
        for(auto x:robots){
            if(x.first<a||x.second<b){
                si=false;
                break;
            }
        }
        if(si){
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<string> board(n);
        vector<pair<int,int>> robots;
        for(int i=0;i<n;++i){
            cin>>board[i];
            for(int j=0;j<board[i].size();++j){
                if(board[i][j]=='R'){
                    robots.push_back({i,j});
                }
            }
        }
        cout<<(isPossible(robots,n,m)?"YES":"NO")<<ENDL;
        

    }
    return 0;
}