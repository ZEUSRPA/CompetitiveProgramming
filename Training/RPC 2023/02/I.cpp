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


struct Node{
    lli l;
    lli r;
    lli speed;
    lli pos;
    Node(){
        l=-1;
        r=-1;
        pos=0;
        speed=0;
    }
};
struct dist{
    lli a;
    lli b;
    dist(){
        a=0;
        b=1;
    }
};
struct Comparator{
    bool operator ()(pair<dist,pair<lli,lli>> a, pair<dist,pair<lli,lli>> b){
        lli one=a.first.a;
        lli two=a.first.b;
        lli three =b.first.a;
        lli four= b.first.b;
        lli current = __gcd(one,two);
        one=one/current;
        two=two/current;
        current= __gcd(three,four);
        three=three/current;
        four=four/current;
        lli alfa=one*four;
        lli beta = two*three;
        return alfa>beta;
    }
};
vector<Node> drones;

pair<bool,dist> getCollision(lli a, lli b){
    dist ans;
    if(a==-1||b==-1){
        return {false,ans};
    }
    if(a<0||b>=drones.size()){
        return {false,ans};
    }
    lli speed = 0;
    if(drones[a].speed<=0 && drones[b].speed>=0){
        return {false,ans};
    }
    if(drones[a].speed>=0 && drones[b].speed<=0){
        speed = drones[a].speed-drones[b].speed;
    }else{
        if(drones[a].speed<0){
            speed = abs(drones[b].speed)-abs(drones[a].speed);
        }else{
            speed = drones[a].speed-drones[b].speed;
        }
    }
    if(speed<=0){
        return {false,ans};
    }
    ans.a=abs(drones[b].pos-drones[a].pos);
    ans.b=speed;
    return {true,ans};
}





int main() {_
    lli n;
    cin>>n;
    drones=vector<Node> (n);
    priority_queue<pair<dist,pair<lli,lli>>,vector<pair<dist,pair<lli,lli>>>,Comparator> nex;
    fore(i,0,n){
        cin>>drones[i].pos>>drones[i].speed;
        if(i>0){
            auto aux = getCollision(i-1,i);
            if(aux.first){
                nex.push({aux.second,{i-1,i}});
            }
            drones[i].l=i-1;
            drones[i-1].r=i;
        }
    }
    vector<bool> visited(n,true);
    while(nex.size()){
        auto current=nex.top();
        nex.pop();
        if(visited[current.second.first]&&visited[current.second.second]){
            visited[current.second.first]=false;
            visited[current.second.second]=false;
            auto aux = getCollision(drones[current.second.first].l,drones[current.second.second].r);
            lli apos=drones[current.second.first].l;
            if(apos!=-1){
                drones[apos].r=drones[current.second.second].r;
            }
            apos = drones[current.second.second].r;
            if(apos!=-1){
                drones[apos].l=drones[current.second.first].l;
            }
            if(aux.first){
                nex.push({aux.second,{drones[current.second.first].l,drones[current.second.second].r}});
            }
        }
    }
    vector<lli> answer;
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
        cout<<answer.back();
    }
    cout<<ENDL;
    return 0;
}