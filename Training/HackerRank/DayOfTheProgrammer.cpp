#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int y;
    cin>>y;
    if(y<1918){
        if(y%4==0){
            cout<<"12.09."<<y<<ENDL;
        }else{
            cout<<"13.09."<<y<<ENDL;
        }
    }else if(y==1918){
        if(y%400==0||(y%4==0 && y%100!=0)){
            cout<<"25.09."<<y<<ENDL;
        }else{
            cout<<"26.09."<<y<<ENDL;
        }
    }else{
        if(y%400==0||(y%4==0 && y%100!=0)){
            cout<<"12.09."<<y<<ENDL;
        }else{
            cout<<"13.09."<<y<<ENDL;
        }
    }
    return 0;
}