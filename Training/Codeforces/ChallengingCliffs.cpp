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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> heights(n);
        for(int i=0;i<n;i++){
            cin>>heights[i];
        }
        sort(heights.begin(),heights.end());
        int x=0, y=1;
        int a,b,resta;
        int dif = 1e9;
        while(y<n){
            resta=heights[y]-heights[x];
            if(resta<=dif){
                a=x;
                b=y;
                dif=resta;
            }
            x++;
            y++;
        }
        int aux1=heights[a];
        int aux2=heights[b];
        heights.erase(heights.begin()+b);
        heights.erase(heights.begin()+a);
        int point=0;
        for(int i=0;i<heights.size();i++){
            if(heights[point]<=aux1){
                int aux = heights[point];
                heights.erase(heights.begin()+point);
                heights.push_back(aux);
            }else{
                point++;
            }
        }
        point=1;
        if(heights.size()>1){

            for(int i = 1; i<heights.size();i++){
                if(heights[point]==heights[point-1]){
                    int aux = heights[point];
                    heights.erase(heights.begin()+point);
                    heights.push_back(aux);
                }else{
                    point++;
                }
            }
        }

        cout<<aux1<<" ";
        for(int i=0;i<heights.size();i++){
            cout<<heights[i]<<" ";
        }
        cout<<aux2<<ENDL;

    }
    return 0;
}

