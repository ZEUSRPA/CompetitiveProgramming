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
    vector<int> nums(n);
    FOR(i,0,n){
        cin>>nums[i];
    }
    vector<vector<int>> current(2,vector<int>((1<<20)+10,0));
    current[1][0]=1;
    int aux=0;
    lli ans=0;
    FOR(i,0,n){
        aux^=nums[i];
        ans+=current[i%2][aux];
        current[i%2][aux]++;
    }
    cout<<ans<<ENDL;

    return 0;
}

//Upsolving problems

//B
//Disktra with updating the node adding one if the time is forbidden, use priority queue to improve the complexity

//C
//Just implementation
//Common problems
//Write down all the conditions and observations, before coding, to divide the modules.


//D
//Simplify the equation
//Verify the numbers of 0s and 1s in the array and use if else for the answer

//E
//Compute the time interval of every vector
//Should be strictly inside the rectangle
//Use fractions with integers to avoid precision problems
//Use math instead of geometry to have exact intersections



//F
//Prefixes with xor

//G
//All the segments to move the segments should be submasks of x
//Sweep line with greedy
//Use precalculation
//Use only the leading zeros to the right


//J

//H
//Use KMP or Z algorithm

//I
//

//Z algorithms
//KMP algorithms Strings



//K
//Use DP with bitmask of the dishes and iterate throug the next to add
//DP two dimensions one bit the mask and the otehr with the last element

//M
//LIS 2D

//I
//Get the diameter
//Find two disjoints paths that are maximum
//DP with rerouting technique
