#include <bits/stdc++.h>
#define ENDL '\n'
#define FOR(a,x,c) for(int i=a;i<x;i+=c)
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,aux,z=1;
    cin>>n;
    map<int,int> nums;
    FOR(1,n+1,1){
        cin>>aux;
        nums[aux]=i;
    }
    while(z++<=n){
        aux=nums[z-1];
        aux=nums[aux];
        cout<<aux<<ENDL;
    }
    return 0;
}