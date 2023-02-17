#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n,aux;
    map<lli,lli> nums;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>aux;
        nums[aux]=i;
    }
    return 0;
}