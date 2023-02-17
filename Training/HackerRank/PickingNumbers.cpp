#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,aux,max=0;
    cin>>n;
    vector<int> numbers(101);
    for(int i=0;i<n;i++){
        cin>>aux;
        numbers[aux]++;
    }
    for(int i=0;i<100;i++){
        if(numbers[i]+numbers[i+1]>max){
            max=numbers[i]+numbers[i+1];
        }
    }
    cout<<max<<ENDL;
    return 0;
}