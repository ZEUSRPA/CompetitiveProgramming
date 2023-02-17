// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define F first
#define S second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define ALL(s) begin(s), end(s)
#define ALLR(s) rbegin(s), rend(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZ(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

int visited[20][20];

void getAns(vector<string> &g,int x, int y,int steps){
    if(x<0||x>=g.size()||y<0||y>=g[0].size()){
        cout<<steps<<" step(s) to exit"<<ENDL;
        return;
    }
    if(visited[x][y]!=-1){
        cout<<steps-(steps-visited[x][y])<<" step(s) before a loop of "<<steps-visited[x][y]<<" step(s)"<<ENDL;
        return;
    }
    visited[x][y]=steps;
    if(g[x][y]=='N'){
        getAns(g,x-1,y,steps+1);
    }else if(g[x][y]=='S'){
        getAns(g,x+1,y,steps+1);
    }else if(g[x][y]=='E'){
        getAns(g,x,y+1,steps+1);
    }else{
        getAns(g,x,y-1,steps+1);
    }
}

int main() {_ 
    int r,c,s;
    
    while(cin>>r>>c>>s){
        if(r==0)break;
        vector<string> g(r);
        memset(visited,-1,sizeof(visited));
        fore(i,0,r){
            cin>>g[i];
        }
        getAns(g,0,s-1,0);
    }

    return 0;
}