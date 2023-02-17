#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

vector<pair<lli,lli>> slots;
vector<pair<lli,lli>> coins;


bool fun(lli a, pair<lli,lli> b){
    return b.first>a;
}

lli distanceCoins(){
    sort(coins.begin(),coins.end());
    lli dis=0;
    for(int j=0;j<slots.size();j++){
        auto end = upper_bound(coins.begin(),coins.end(),slots[j].first,fun);
        
        for(auto ptr=coins.begin();ptr != end; ptr++){
            if (ptr->second >= slots[j].second)
            {
                coins.erase(ptr);
                ptr--;
                end--;
                dis += j + 1;
            } 
        }
    }
    return dis;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli s,w,m,c;
    cin>>s;
    slots.resize(s);
    for(int i=0;i<s;i++){
        cin>>slots[i].first>>slots[i].second;
    }
    cin>>c;
    coins.resize(c);
    for(int i=0;i<c;i++){
        cin>>coins[i].first>>coins[i].second;
    }
    cout<<distanceCoins()<<ENDL;
    return 0;
}