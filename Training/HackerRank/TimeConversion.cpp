#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string times;
    cin>>times;
    if(times.find('A')!=string::npos){
        if(times[0]=='1'&&times[1]=='2'){
            times[0]='0';
            times[1]='0';
        }
    }else{
        if(!(times[0]=='1'&&times[1]=='2')){            int aux=times[1]-'0'+2;
            if(aux>9){
                times[1]=aux-10+'0';
                times[0]=times[0]+aux+1;
            }else{
                times[1]=aux+'0';
                times[0]++;
            }
        }
    }
    times.pop_back();
    times.pop_back();
    cout<<times<<ENDL;
    return 0;
}