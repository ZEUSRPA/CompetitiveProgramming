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

double dp[305][305][305];

// double prob(int a,int b, int c,double n){
//     if(a==0&&b==0&&c==0){
//         return 0;
//     }
//     if(dp[a][b][c]!=0){
//         return dp[a][b][c];
//     }
//     double p=0.0;
//     double pa=0;
//     double pbb=0;
//     double pc=0;
//     if(a!=0){
//         pa=(double)a*prob(a-1,b,c,n);
//     }
//     if(b!=0){
//         pbb=(double)b*prob(a+1,b-1,c,n);
//     }
//     if(c!=0){
//         pc=(double)c*prob(a,b+1,c-1,n);
//     }
//     p=n/(double)(a+b+c);
//     p+=(pa+pbb+pc)/(double)(a+b+c);
//     dp[a][b][c]=p;
//     return dp[a][b][c];
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a;
    cin>>n;
    vector<int> aux(4,0);
    for(int i=0;i<n;++i){
        cin>>a;
        aux[a]++;
    }
    dp[0][0][0]=0;
    for(int c=0;c<=n;++c){
        for(int b=0;b<=n;++b){
            for(int a=0;a<=n;++a){
                // prob(a,b,c,(double)n);
                double k=a+b+c;
                if(k<=0||k>n){
                    continue;
                }
                dp[a][b][c]=(double)n/k+((a?a*dp[a-1][b][c]:0)+(b?b*dp[a+1][b-1][c]:0)+(c?c*dp[a][b+1][c-1]:0))/k;
            }
        }
    }

    cout<<fixed<<setprecision(10)<<dp[aux[1]][aux[2]][aux[3]]<<ENDL;
    
    return 0;
}

