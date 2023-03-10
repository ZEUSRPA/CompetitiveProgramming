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
    vector<bool> visited(720,false);
    int n,x,y;
    cin>>n;
    vector<int> points(n);
    fore(i,0,n){
        cin>>x>>y;
        y+=180;
        y*=2;
        points[i]=y;
    }
    fore(i,0,sz(points)){
        bool one=true;
        int target = i+1;
        target%=n;
        if(abs(points[i]-points[target])==360){
            fore(j,0,720){
                visited[j]=true;
            }
            break;
        }
        if(abs(points[i]-points[target])>360){
            one=false;
        }
        if(one){
            fore(j,min(points[i],points[target]),max(points[i],points[target])+1){
                visited[j]=true;
            }
        }else{
            fore(j,0,min(points[i],points[target])+1){
                visited[j]=true;
            }
            fore(j,max(points[i],points[target]),sz(visited)){
                visited[j]=true;
            }
        }
    }
    
    bool si=true;
    fore(i,0,sz(visited)){
        if(visited[i]==false){
            double  lon = double(i)/2.0;
            lon-=180;
            cout<<fixed<<setprecision(1)<<"no "<<lon<<ENDL;
            si=false;
            break;
        }
    }
    if(si){
        cout<<"yes"<<ENDL;
    }
    
    return 0;
}