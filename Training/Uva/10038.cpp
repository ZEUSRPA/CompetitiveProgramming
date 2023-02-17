#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,aux,c;
    while(cin>>n){

        map<int,int> nums;
        cin>>c;
        for(int i=1;i<n;i++){
            cin>>aux;
            int a=abs(aux-c);
            nums[a-1]=0;
            c=aux;
        }
        bool si=true;
        for(int i=0;i<n-1;i++){
            if(nums.count(i)==0){
                si=false;
                break;
            }
        }
        cout<<(si?"Jolly":"Not jolly")<<ENDL;
    }
    return 0;
}