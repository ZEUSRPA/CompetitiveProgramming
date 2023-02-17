#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

vector<int> numbers;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n;
    cin>>t;
   
    while(t--){
        cin>>n;
        int max=0;
        bool si=true;
        numbers.clear();
        numbers.resize(n);
        for(int i=0;i<n;i++){
            cin>>numbers[i];
            if(numbers[i]>max){
                max=numbers[i];
            }
        }
        for(auto x:numbers){
            if((max-x)%2!=0){
                si=false;
                break;
            }
        }
        cout<<(si?"YES":"NO")<<ENDL;
        
    }
    return 0;
}