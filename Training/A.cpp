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

int getMs(string s){
    string current="";
    bool flag=false;
    fore(i,0,sz(s)){
        if(s[i]==' '){
            if(current=="GRANTED"){
                return -1;
            }
            if(flag){
                return stoi(current);
            }
            current="";
        }else if(s[i]=='('){
            flag=true;
            current="";
        }
    }
    return 0;
}

int main() {
    int length=0;
    string aux="a",s;
    while(true){
        cout<<aux<<ENDL;
        getline(cin,s);
        if(getMs(s)>5){
            length=aux.size();
            break;
        }
        aux+="a";
    }
    int current = 9;
    string possible="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int pos=1;
    int updating=0;
    while(true){
        cout<<aux<<ENDL;
        getline(cin,s);
        int res=getMs(s);
        res-=5;
        if(res==-1){
            break;
        }else if(res>current){
            pos=1;
            updating++;
            current+=9;
        }else{
            aux[updating]=possible[pos++];
        }
    }
    
    return 0;
}