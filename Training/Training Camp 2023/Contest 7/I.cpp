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

struct Point{
    lli x;
    lli y;
    lli z;
};

bool compare(lli a, lli b, lli c ,lli d){
    lli sup = a*d;
    lli dow=b*c;
    return sup==dow;
}

bool isEqual(Point x, Point y){
    lli a=0;
    lli b=0;
    bool found=false;
    if(x.x!=0&&y.x!=0){
        if(!found){
            found=true;
            a=x.x;
            b=y.x;
        }
    }else{
        if(x.x!=y.x){
            return false;
        }
    }

    if(x.y!=0&&y.y!=0){
        if(!found){
            found=true;
            a=x.y;
            b=y.y;
        }else{
            if(!compare(a,b,x.y,y.y)){
                return false;
            }
        }
    }else{
        if(x.y!=y.y){
            return false;
        }
    }

    if(x.z!=0&&y.z!=0){
        if(!found){
            found=true;
            a=x.z;
            b=y.z;
        }else{
            if(!compare(a,b,x.z,y.z)){
                return false;
            }
        }
    }else{
        if(x.z!=y.z){
            return false;
        }
    }
    return true;
}

void visit(vector<Point> &planets, vector<bool> &visited, lli current){
    fore(i,0,planets.size()){
        if(!visited[i]){
            if(isEqual(planets[current],planets[i])){
                visited[i]=true;
            }
        }
    }
}


int main() {_ 
    int n;
    cin>>n;
    vector<Point> planets(n);
    cin>>planets[0].x>>planets[0].y>>planets[0].z;
    fore(i,1,n){
        cin>>planets[i].x;
        cin>>planets[i].y;
        cin>>planets[i].z;
        planets[i].x-=planets[0].x;
        planets[i].y-=planets[0].y;
        planets[i].z-=planets[0].z;
    }

    lli ans = 0;
    vector<bool> visited(n,false);
    visited[0]=true;
    fore(i,0,n){
        if(!visited[i]){
            ans++;
            visited[i]=true;
            visit(planets,visited,i);
        }
    }
    cout<<ans<<ENDL;

    return 0;
}