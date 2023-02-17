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

void fun(vector<string> &matrix,int e){
    int i=0,j=e-1;
    int steps=0;
    int ls=0;
    bool loop=false;
    vector<vector<int>> visited(matrix.size(),vector<int>(matrix[0].size(),-1));
    while(true){
        if(i<0||i==matrix.size()||j<0||j==matrix[0].size()){
            cout<<steps<<" step(s) to exit"<<ENDL;
            break;
        }
        if(visited[i][j]!=-1){
            cout<<visited[i][j]-1<<" step(s) before a loop of "<<steps-visited[i][j]+1<<" step(s)"<<ENDL;   
            break;     
        }
        steps++;
        visited[i][j]=steps;
        if(matrix[i][j]=='N'){
            i--;
        }else if(matrix[i][j]=='S'){
            i++;
        }else if(matrix[i][j]=='E'){
            j++;
        }else if(matrix[i][j]=='W'){
            j--;
        }

    }


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r,c,e;
    while(cin>>r){
        cin>>c>>e;
        if(r==0&&c==0&&e==0){
            break;
        }
        vector<string> matrix(r);
        FOR(i,0,r){
            cin>>matrix[i];
        }
        fun(matrix,e);
    }

    return 0;
}