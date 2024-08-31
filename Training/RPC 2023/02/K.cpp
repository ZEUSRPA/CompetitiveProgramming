// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define F first
#define S second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define ALL(s) begin(s), end(s)
#define ALLR(s) rbegin(s), rend(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

vector<pair<int,int>> drones;

double getCollision(int a, int b){
    if(a<0||b>=drones.size()){
        return -1;
    }
    double ans=0;
    double speed = 0;
    if(drones[a].second<=0 && drones[b].second>=0){
        return -1;
    }
    if(drones[a].second>=0 && drones[b].second<=0){
        speed = drones[a].second-drones[b].second;
    }else{
        if(drones[a].second<0){
            speed = abs(drones[b].second)-abs(drones[a].second);
        }else{
            speed = drones[a].second-drones[b].second;
        }
    }
    if(speed<=0){
        return -1;
    }
    ans=double(abs(drones[b].first-drones[a].first))/speed;
    return ans;
}

int main() {_
    int n;
    cin>>n;
    drones=vector<pair<int,int>> (n);
    priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>> nex;
    fore(i,0,n){
        cin>>drones[i].first>>drones[i].second;
        if(i!=0){
            double aux = getCollision(i-1,i);
            if(aux>0){
                nex.push({aux,{i-1,i}});
            }
        }
    }
    vector<bool> visited(n,true);
    while(nex.size()){
        auto current=nex.top();
        nex.pop();
        if(visited[current.second.first]&&visited[current.second.second]){
            visited[current.second.first]=false;
            visited[current.second.second]=false;
            double aux = getCollision(current.second.first-1,current.second.second+1);
            if(aux>0){
                nex.push({aux,{current.second.first-1,current.second.second+1}});
            }
        }
    }
    vector<int> answer;
    fore(i,0,n){
        if(visited[i]){
            answer.pb(i+1);
        }
    }
    cout<<answer.size()<<ENDL;
    if(answer.size()>0){
        fore(i,0,sz(answer)-1){
            cout<<answer[i]<<" ";
        }
        cout<<answer.back()<<ENDL;
    }
    return 0;
}