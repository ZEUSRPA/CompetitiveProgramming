// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define F first
#define S second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
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
    lli t,n,points,beasts,mark;
    cin>>t;
    while(t--){
        points=1;
        beasts=1;
        cin>>n;
        vector<int> marks(n);
        fore(i,0,n){
            cin>>marks[i];
        }
        vector<int> pref(n,0);
        pref[n-1] = (marks[n-1]==-1?2:0);
        for(int i=n-2;i>=0;i--){
            if(marks[i]==-1){
                if(pref[i+1]>0){
                    pref[i]=pref[i+1]+1;
                }else{
                    pref[i]=2;
                }
            }else if(marks[i]==1){
                pref[i]=pref[i+1]-1;
            }else{
                pref[i]=pref[i+1];
            }
        }
        fore(i,0,n){
            if(marks[i]==-1){
                if(beasts>=2){
                    beasts--;
                }else{
                    points=-1;
                    break;
                }
            }else if(marks[i]==1){
                beasts++;
                points++;
            }else{
                if(pref[i]>=beasts){
                    beasts++;
                    points++;
                }else{
                    if(beasts>=2){
                        beasts--;
                    }else{
                        beasts++;
                        points++;
                    }
                }
            }
        }
        if(points==-1){
            cout<<-1<<ENDL;
        }else{
            cout<<points/__gcd(beasts,points)<<" "<<beasts/__gcd(beasts,points)<<ENDL;
        }
    }
    return 0;
}