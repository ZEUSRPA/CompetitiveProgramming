#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k,x,y,xp,yp;
    while(cin>>k){
        if(k==0){
            break;
        }
        cin>>xp>>yp;
        while(k--){
            cin>>x>>y;
            if(x==xp || y==yp){
                cout<<"divisa"<<ENDL;
            }else if(x>xp){
                if(y<yp){
                    cout<<"SE"<<ENDL;
                }else{
                    cout<<"NE"<<ENDL;
                }
            }else{
                if(y<yp){
                    cout<<"SO"<<ENDL;
                }else{
                    cout<<"NO"<<ENDL;
                }
            }
        }
    }

    return 0;
}