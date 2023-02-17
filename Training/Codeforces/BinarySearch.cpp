#include <bits/stdc++.h>
#define ENDL '\n'

using namespace std;

bool binary(vector<int> &nums, int x){
    int current=0;
    for(int p=nums.size();p;p/=2){
        while(current+p<nums.size()&&nums[current+p]<=x){
            current+=p;
        }
    }
    return nums[current]==x;
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
    int x;
    while(k--){
        cin>>x;
        cout<<(binary(nums,x)?"YES":"NO")<<ENDL;
    }
    return 0;
}