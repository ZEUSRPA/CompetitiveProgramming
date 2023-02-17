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

unordered_map<int,unordered_map<int,bool>> board;
unordered_map<int,unordered_map<int,bool>> uattack;

void alfil(int i, int j){
    FOR(k,1,9){
        uattack[i+k][j+k]=true;
        if(board[i+k][j+k]){
            break;
        }
    }
    FOR(k,1,9){
        uattack[i-k][j+k]=true;
        if(board[i-k][j+k]){
            break;
        }
    }
    FOR(k,1,9){
        uattack[i+k][j-k]=true;
        if(board[i+k][j-k]){
            break;
        }
    }
    FOR(k,1,9){
        uattack[i-k][j-k]=true;
        if(board[i-k][j-k]){
            break;
        }
    }
}

void torre(int i,int j){
    FOR(k,1,9){
        uattack[i+k][j]=true;
        if(board[i+k][j]){
            break;
        }
    }
    FOR(k,1,9){
        uattack[i-k][j]=true;
        if(board[i-k][j]){
            break;
        }
    }
    FOR(k,1,9){
        uattack[i][j-k]=true;
        if(board[i][j-k]){
            break;
        }
    }
    FOR(k,1,9){
        uattack[i][j+k]=true;
        if(board[i][j+k]){
            break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(cin>>s){
        board.clear();
        uattack.clear();
        int i=1,j=1;
        for(auto x:s){
            if(x=='/'){
                j++;
                i=1;
            }else if(isdigit(x)){
                i+=x-'0';
            }else if(x=='p'){
                board[i][j]=true;
                uattack[i][j]=true;
                i++;
            }else if(x=='P'){
                board[i][j]=true;
                uattack[i][j]=true;
                i++;
            }else if(x=='n' || x=='N'){
                board[i][j]=true;
                uattack[i][j]=true;
                i++;
            }else if(x=='b' || x=='B'){
                board[i][j]=true;
                uattack[i][j]=true;
                i++;
            }else if(x=='r' || x=='R'){
                board[i][j]=true;
                uattack[i][j]=true;
                i++;
            }else if(x=='q' || x=='Q'){
                board[i][j]=true;
                uattack[i][j]=true;
                i++;
            }else if(x=='k' || x=='K'){
                board[i][j]=true;
                uattack[i][j]=true;
                i++;
            }
        }
        i=1;
        j=1;
        for(auto x:s){
            if(x=='/'){
                j++;
                i=1;
            }else if(isdigit(x)){
                i+=x-'0';
            }else if(x=='p'){
                uattack[i+1][j+1]=true;
                uattack[i-1][j+1]=true;
                i++;
            }else if(x=='P'){
                uattack[i-1][j-1]=true;
                uattack[i+1][j-1]=true;
                i++;
            }else if(x=='n' || x=='N'){
                uattack[i+1][j+2]=true;
                uattack[i-1][j+2]=true;
                uattack[i+2][j+1]=true;
                uattack[i-2][j+1]=true;
                uattack[i+2][j-1]=true;
                uattack[i-2][j-1]=true;
                uattack[i+1][j-2]=true;
                uattack[i-1][j-2]=true;
                i++;
            }else if(x=='b' || x=='B'){
                alfil(i,j);
                i++;
            }else if(x=='r' || x=='R'){
                torre(i,j);
                i++;
            }else if(x=='q' || x=='Q'){
                alfil(i,j);
                torre(i,j);
                i++;
            }else if(x=='k' || x=='K'){
                uattack[i+1][j]=true;
                uattack[i+1][j+1]=true;
                uattack[i][j+1]=true;
                uattack[i-1][j+1]=true;
                uattack[i-1][j]=true;
                uattack[i-1][j-1]=true;
                uattack[i][j-1]=true;
                uattack[i+1][j-1]=true;
                i++;
            }
        }
        int cont=0;
        FOR(z,1,9){
            FOR(x,1,9){
                if(!uattack[z][x]){
                    cont++;
                }
            }
        }
        cout<<cont<<ENDL;
    }
    return 0;
}