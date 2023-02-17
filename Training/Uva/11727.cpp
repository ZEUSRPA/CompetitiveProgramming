#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,aux,a=1;
    cin>>t;
    while(a<=t){
        vector<int> salary;
        for(int i=0;i<3;i++){
            cin>>aux;
            salary.push_back(aux);
        }
        sort(salary.begin(),salary.end());
        cout<<"Case "<<a<<": "<<salary[1]<<ENDL;
        a++;
    }
    return 0;
}