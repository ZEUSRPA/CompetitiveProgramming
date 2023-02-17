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

vector<vector<bool>> visited;


int getMax(vector<vector<int>> &matrix,int i, int j){
    queue<pair<int,int>> next;
    next.push({i,j});
    int res=1;
    visited[i][j]=true;
    vector<pair<int,int>> steps={{-1,0},{-1,-1},{-1,1},{0,-1},{0,1},{1,0},{1,-1},{1,1}};
    while(next.size()){
        auto current=next.front();
        next.pop();
        for(auto x:steps){
            int a=current.first+x.first;
            int b=current.second+x.second;
            if(a>=0&&a<matrix.size()&&b>=0&&b<matrix[0].size()&&matrix[a][b]==1&&visited[a][b]==false){
                visited[a][b]=true;
                next.push({a,b});
                res++;
            }
        }
    }

    return res;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,r,c;
    int cas=1;
    cin>>t;
    while(cas<=t){
        cin>>r>>c;
        vector<vector<int>> matrix(r,vector<int>(c));
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                cin>>matrix[i][j];
            }
        }
        visited=vector<vector<bool>> (r,vector<bool>(c,false));
        int res=0;
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                if(!visited[i][j]&&matrix[i][j]==1){
                    res=max(res,getMax(matrix,i,j));
                }
            }
        }
        cout<<"Case #"<<cas<<": "<<res<<ENDL;
        cas++;
    }
    return 0;
}