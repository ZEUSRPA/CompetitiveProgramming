#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int f,c1,c2,c3;
    while(true){
        int degrees=360*3;
        int distance=0;
        bool clockwise=true;
        cin>>f>>c1>>c2>>c3;
        if(f==0 && c1==0 && c2==0 && c3==0){
            break;
        }
        distance=min(abs(c1-f),40-(f-c1));
        if(distance<0){
            distance+=40;
        }
        degrees+=9*distance;
        distance=c1-c2;
        if(distance<0){
            distance+=40;
        }
        degrees+=9*distance;
        distance=c3-c2;
        if(distance<0){
            distance+=40;
        }
        degrees+=9*distance;
        cout<<degrees<<ENDL;
    }
    return 0;
}