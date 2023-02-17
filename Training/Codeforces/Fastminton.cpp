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
    string s;
    cin>>s;
    vector<int> points(2,0);
    vector<int> won(2,0);
    bool left=true;
    for(int i=0;i<s.size();++i){
        if(s[i]=='S'){
            if(left){
                points[0]++;
                if((points[0]-points[1]>=2&&points[0]>=5)||points[0]==10){
                    won[0]++;
                    points[0]=0;
                    points[1]=0;
                }
            }else{
                points[1]++;
                if((points[1]-points[0]>=2&&points[1]>=5)||points[1]==10){
                    won[1]++;
                    points[0]=0;
                    points[1]=0;
                }
            }
        }else if(s[i]=='R'){
            if(left){
                points[1]++;
                if((points[1]-points[0]>=2&&points[1]>=5)||points[1]==10){
                    won[1]++;
                    points[0]=0;
                    points[1]=0;
                }
                left=false;
            }else{
                points[0]++;
                if((points[0]-points[1]>=2&&points[0]>=5)||points[0]==10){
                    won[0]++;
                    points[0]=0;
                    points[1]=0;
                }
                left=true;
            }
        }else{
            if(won[0]==2||won[1]==2){
                cout<<won[0]<<(won[0]>won[1]?" (winner) ":"")<<" - "<<won[1]<<(won[1]>won[0]?" (winner) ":"")<<ENDL;
                won[0]=0;
                won[1]=1;
                points[0]=0;
                points[1]=0;
            }else{

                cout<<won[0]<<" "<<"("<<points[0]<<(left?"*":"")<<") - "<<won[1]<<" ("<<points[1]<<(!left?"*":"")<<")"<<ENDL;
            }
        }
    }
    return 0;
}