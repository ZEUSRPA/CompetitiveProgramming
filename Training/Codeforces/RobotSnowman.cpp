#include <bits/stdc++.h>
#define ENDL '\n'
#define FOR(i,a,n) for(int i=(a);i<(n);i++)
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double s,c=1.0/3.0;
    cin>>s;
    cout<<fixed<<setprecision(10)<<pow((s/153.0),c)<<ENDL;
    return 0;
}