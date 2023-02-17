#include <bits/stdc++.h>
#define ENDL '\n'

using namespace std;

long double getTime(vector<long double> &laser,long double target){
    long double ans=0.0;
    for(int i=0;i<laser.size();++i){
        ans+=abs(target-laser[i]);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n;
    long double k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<long double> laser(n);
        for(int i=0;i<n;++i){
            cin>>laser[i];
        }
        long double m1,m2,l=0.0,r=1000000000.0;

        while(r-l>1e-4){
            m1=l+(r-l)/3;
            m2=r-(r-l)/3;
            long double r1=getTime(laser,m1);
            long double r2=getTime(laser,m2);
            if(r1>r2){
                l=m1;
            }else{
                r=m2;
            }
        }
        

        auto answer= getTime(laser,m1+(m2-m1)/2);
        
        cout<<fixed<<setprecision(6)<<answer<<ENDL;
        if(answer<=k){
            cout<<"May the Force be with you"<<ENDL;
        }else{
            cout<<"It's a trap!"<<ENDL;
        }
    }
    return 0;
}