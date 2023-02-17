#include <bits/stdc++.h>
#define ENDL '\n'
#define FOR(i,a,n) for(int i=(a);i<(n);i++)
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int x=0,y=0,a;
    string pos="NESO";
    int p=0;
    char c;
    while(n--){
        cin>>c;
        if(c=='F'){
            cin>>a;
            if(pos[p]=='N'){
                y+=a;
            }else if(pos[p]=='S'){
                y-=a;
            }else if(pos[p]=='E'){
                x+=a;
            }else{
                x-=a;
            }
        }else if(c=='R'){
            p++;
            p%=4;
        }else{
            p--;
            if(p<0){
                p+=4;
            }
        }
    }
    cout<<x<<" "<<y<<ENDL;
    return 0;
}