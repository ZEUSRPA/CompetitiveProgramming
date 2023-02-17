#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,cont=0;
    cin>>n>>m;
    vector<int> as(n);
    vector<int> bs(m);
    for(int i=0;i<n;i++){
        cin>>as[i];
    }
    for(int i=0;i<m;i++){
        cin>>bs[i];
    }
    sort(as.begin(),as.end());
    sort(bs.begin(),bs.end());

    for(int i=as[0];i<=bs[m-1];i++){
        bool si=true;
        for(auto x:as){
            if(i%x!=0){
                si=false;
                break;
            }
        }
        if(si){
            for(auto x:bs){
                if(x%i!=0){
                    si=false;
                    break;
                }
            }
        }
        if(si){
            cont++;
        }
    }
    cout<<cont<<ENDL;

    return 0;
}