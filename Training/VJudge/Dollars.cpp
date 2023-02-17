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
#define SZ(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

const lli MAXN=100000;

vector<lli> coins;
lli dp[MAXN][20];

lli getAns(lli value,int pos){
    if(value==0){
        return 1;
    }
    if(dp[value][pos]!=-1){
        return dp[value][pos];
    }
    lli ans=0;
    // for(auto x:coins){
    //     if(x<=value){
    //         ans+=getAns(value-x);
    //     }
    // }
    fore(i,pos,coins.size()){
        int c=coins[i];
        while(c<=value){
            ans+=getAns(value-c,i+1);
            c+=coins[i];
        }
    }
    dp[value][pos]=ans;
    return dp[value][pos];
}

int main() {_ 
    string s;
    coins = vector<lli> {10000,5000,2000,1000,500,200,100,50,20,10,5};
    memset(dp,-1,sizeof(dp));
    while(cin>>s){
        if(s=="0.00")break;
        int value = 0;
        string aux="";
        for(auto x:s){
            if(x=='.'){
                value+=stoi(aux)*100;
                aux="";
            }else{
                aux+=x;
            }
        }
        if(aux.size()==1){
            aux+='0';
        }
        value+=stoi(aux);
        fore(i,0,6-s.size()){
            cout<<" ";
        }
        cout<<s;
        string prin=to_string(getAns(value,0));
        fore(i,0,17-prin.size()){
            cout<<" ";
        }
        cout<<prin<<ENDL;
    }
    return 0;
}