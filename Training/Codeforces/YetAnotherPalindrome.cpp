#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

vector<int> numbers;

bool good(){
    
    for(int i=0;i<numbers.size()-2;i++){
        int l=i;
        set<int> pos;
        int r=numbers.size();
        while(l<=r){
            if(numbers[l]==numbers[r]){
                pos.insert(l);
                pos.insert(r);
                l++;
                r--;
            }else
            {
                r--;
            }
        }
        if(pos.size()>=3){
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        numbers.clear();
        numbers.resize(n);
        for(int i=0;i<n;i++){
            cin>>numbers[i];
        }
        cout<<(good()?"YES":"NO")<<ENDL;
    }
    return 0;
}