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

void bfs(vector<string> &image,pair<int,int> pos){
    queue<pair<int,int>> nex;
    vector<pii> steps={{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
    nex.push(pos);
    image[pos.first][pos.second]='0';
    while(nex.size()){
        auto current=nex.front();
        nex.pop();
        for(auto x:steps){
            int a=current.first+x.first;
            int b=current.second+x.second;
            if(a>=0&&a<image.size()&&b>=0&&b<image[0].size()&&image[a][b]=='1'){
                nex.push({a,b});
                image[a][b]='0';
            }
        }

    }

}

int main()
{
    IO;
    int n;
    int c=1;
    while(cin>>n){
        vector<string> image(n);
        FOR(i,0,n){
            cin>>image[i];
        }
        int cont=0;
        FOR(i,0,n){
            FOR(j,0,n){
                if(image[i][j]=='1'){
                    cont++;
                    bfs(image,{i,j});
                }
            }
        }
        cout<<"Image number "<<c++<<" contains "<<cont<<" war eagles."<<ENDL;

    }
    return 0;
}