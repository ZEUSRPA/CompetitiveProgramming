#include <bits/stdc++.h>
#define ENDL '\n'

using namespace std;

int binary(vector<int> &nums){
    int current=-1;
    for(int p=nums.size();p;p/=2){
        while(current+p<nums.size()&&nums[current+p]<=240){
            current+=p;
        }
    }
    return current+1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> aux(n,0);
    aux[0]=5;
    aux[0]+=k;
    for(int i=2;i<=n;++i){
        aux[i-1]=aux[i-2]+5*i;
    }
    cout<<binary(aux)<<ENDL;

    return 0;
}