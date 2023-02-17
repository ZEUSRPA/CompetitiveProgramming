#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // 
    ///use & to check if a number is pair or not
    // if(aux&1){
    //     cout<<"ODD"<<ENDL;
    // }else
    // {
    //     cout<<"EVEN"<<ENDL;
    // }
    ///swap two variables fast and without another variable
    int a,b;
    cin>>a>>b;
    a^=b;
    b^=a;
    a^=b;
    cout<<"A: "<<a<<ENDL;
    cout<<"B: "<<b<<ENDL;
    ///gcd with a c++ function
    cout<<__gcd(a,b)<<ENDL;
    ///know numbers of digits on a number
    cout<<floor(log10(a))+1<<ENDL;
    

    
    return 0;
}