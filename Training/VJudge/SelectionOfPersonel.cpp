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

//n!
//k!(n-k)!
void generateCombinations(vector<vector<lli>> &matrix){

    FOR(i,0,matrix.size()){
        matrix[i][0]=1;
        matrix[i][1]=i;
    }
    matrix[1][1]=1;
    FOR(i,2,matrix.size()){
        FOR(j,2,matrix[0].size()){
            matrix[i][j]=matrix[i-1][j]+matrix[i-1][j-1];
        }
    }
}

int main()
{
    IO;
    lli n;
    cin>>n;
    vector<vector<lli>> matrix(n+1,vector<lli>(8,0));
    generateCombinations(matrix);
    lli ans=matrix[n][5]+matrix[n][6]+matrix[n][7];
    cout<<ans<<ENDL;

    return 0;
}