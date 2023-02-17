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

const int neut=0; //neut value

int op(int ans, int value){
    //operation
}

int query(int l, int r){
    int bl = l/s;
    int br = r/s;
    int ans = neut;
    if(bl == br){
        for(int i=l; i<=r; i++){
            ans=op(ans,a[i]);
        }
    }else{
        int ans=neut;
        //partial blocks, at most two
        for(int i =l; i<s*(bl+1);i++){
            ans=op(ans, a[i]);
        }
        for(int i =s*br; i<=r;i++){
            ans=op(ans, a[i]);
        }
        //complete blocks
        for(int i=bl+1; i<br; i++){
            ans=op(ans,block[i]);
        }

    }
}

void function2(){

}

int main()
{
    IO;
    
    return 0;
}
