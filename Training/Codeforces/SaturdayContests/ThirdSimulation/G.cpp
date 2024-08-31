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

int matrix[4][4];
int mask;

bool isValid(){
    int total=-1;
    int current;
    fore(i,0,4){
        current=0;
        fore(j,0,4){
            current+=matrix[i][j];
        }
        if(total!=-1){
            if(total!=current){
                return false;
            }
        }else{
            total=current;
        }
    }
    fore(i,0,4){
        current=0;
        fore(j,0,4){
            current+=matrix[j][i];
        }
        if(total!=current){
            return false;
        }
    }
    return true;

}

bool getAns(int x, int y){
    int a=x;
    int b=y+1;
    if(b==4){
        a++;
        b=0;
    }
    if(matrix[x][y]==-1){
        fore(i,1,17){
            if((mask&(1<<i))==0){
                matrix[x][y]=i;
                mask|=(1<<i);
                if(x==3&&y==3){
                    if(isValid()){
                        return true;
                    }
                }else if(getAns(a,b)){
                    return true;
                }
                mask^=(1<<i);
            }
        }
        matrix[x][y]=-1;
    }else{
        if(x==3&&y==3){
            if(isValid()){
                return true;
            }
        }else{
            if(getAns(a,b)){
                return true;
            }
        }
    }
    return false;
}

int main() {_ 
    int t;
    cin>>t;
    int c=1;
    while(t--){
        mask=0;
        fore(i,0,4){
            fore(j,0,4){
                cin>>matrix[i][j];
                if(matrix[i][j]!=-1){
                    mask|=(1<<matrix[i][j]);
                }
            }
        }
        getAns(0,0);
        cout<<"Case "<<c++<<":"<<ENDL;
        fore(i,0,4){
            fore(j,0,4){
                cout<<matrix[i][j];
                if(j<3){
                    cout<<" ";
                }
            }
            cout<<ENDL;
        }
    }
    return 0;
}