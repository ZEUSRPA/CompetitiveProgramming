#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n,c,cont=0;
    cin>>n>>c;
    vector<lli> w(n);
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    sort(w.begin(),w.end());
    lli l=0,r=w.size()-1;
    while(l<=r){
        if(l!=r){
            if(w[l]+w[r]<=c){
                l++;
                r--;
                cont++;
            }else{
                cont++;
                r--;
            }
        }else
        {
            cont++;
            r--;
        }
    }
    cout<<cont<<ENDL;
    return 0;
}