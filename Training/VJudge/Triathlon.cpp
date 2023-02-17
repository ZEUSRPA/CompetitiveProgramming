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
#define sz(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

int main() {_ 
    int n;
    cin>>n;
    vector<vector<int>> speeds(n, vector<int> (3));
    fore(i,0,n){
        cin>>speeds[i][0]>>speeds[i][1]>>speeds[i][2];
    }
    fore(i,0,n){
        bool si=true;
        vector<bool> used(3,false);
        int found = 0;
        fore(j,0,n){
            if(j==i)continue;
            int pos=0;
            bool aux=false;
            while(pos<3){
                if(speeds[i][pos]>speeds[j][pos]){
                    if(!used[pos]){
                        aux=true;
                    }
                }else if(speeds[i][pos]<speeds[j][pos]){
                    used[pos]=true;
                }
                pos++;
            }
            if(!aux){
                si=false;
                break;
            }
        }
        cout<<(si?"Yes":"No")<<ENDL;
    }
    return 0;
}