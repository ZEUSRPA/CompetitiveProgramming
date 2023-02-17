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

int main()
{
    IO;
    int n;
    cin>>n;
    lli ans=0;
    if(n>4){
        ans = 8+(((n-4)/3)*4);
        if((n-4)%3==1){
            ans++;
        }else if((n-4)%3==2){
            ans+=3;
        }
    }else{
        if(n==1){
            ans = 3;
        }else if(n==2){
            ans=5;
        }else if(n==3){
            ans =7;
        }else{
            ans=8;
        }

    }
    cout<<ans<<ENDL;
    return 0;
}

//Upsolving

//L
//Find the pattern
//Square difference

//D
//DP over digits 
//d[0][0][k]
//pos 2 #0

//E
//Binary search
//All the question should be over the same line
//At the end print x+1 y+1, x-1,y-1

//H
//DP
//dp[pos][s1][c]
//

//J
//Contructive problem
//Think how to solve the problem using just one file
//Then use this techique to solve the 2D matrix

//B
//Use a BFS multiple
//Use deque to devide all with cost 0 and cost 1


//M
//Do assumptions
//Use segment tree to optimize the solution
//Compute two cases when pj<pi and when pi<pj
//Use this technique when the graph is dense
//Get all the non-visited neighbors fast using the segment tree

//I
//Use bitset
//Use Lazy tree
//To update the bitset use cyclic rotation
//

//Investigate bitset to solve solutions using bits,


//G
//Virtual tree


//C
//Square decomposition
