#include <bits/stdc++.h>
#define ENDL '\n'

using namespace std;

bool posible(vector<int>& nums,int k,long long int target){
    for(int i=nums.size()/2;i<nums.size();++i){
        if(nums[i]<target){
            k-=target-nums[i];
            if(k<0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    long long int current=0;
    long long int maximo=2e9;
    for(int p=maximo;p;p/=2){
        while(current+p<=maximo && posible(nums,k,current+p)){
            current+=p;
        }
    }
    cout<<current<<ENDL;

    return 0;
}