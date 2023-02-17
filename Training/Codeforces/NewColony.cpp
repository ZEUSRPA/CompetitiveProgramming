#include <bits/stdc++.h>
#define ENDL '\n'
#define FOR(i,a,n) for(int i=(a);i<(n);i++)
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> mountains(n+1);
        mountains[n]=0;
        FOR(i,0,n){
            cin>>mountains[i];
        }
        int aux;
        bool fin;
        int last=mountains[0];
        FOR(i,0,k){
            aux=-1;
            fin=true;
            FOR(j,0,n){
                if(mountains[j]<mountains[j+1]){
                    mountains[j]++;
                    aux=j+1;
                    fin=false;
                    break;
                }
            }
            if(fin){
                break;
            }
        }
        
        cout<<aux<<ENDL;
    }
    return 0;
}