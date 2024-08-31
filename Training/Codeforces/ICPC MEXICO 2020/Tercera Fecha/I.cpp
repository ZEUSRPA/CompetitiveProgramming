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

string nextP(string s){
    string aux="";
    fore(i,1,sz(s)){
        aux+=s[i];
    }
    aux+=s[0];
    return aux;
}

int main() {_ 
    vector<int> books(3);
    cin>>books[0]>>books[1]>>books[2];
    int best=INT_MAX;
    int current=0;
    fore(i,0,3){
        if(books[i]>=500){
            current+=books[i]-100;
        }else{
            current+=books[i];
        }
    }
    best=min(current,best);
    if(books[0]+books[1]+books[2]>=500){
        current=books[0]+books[1]+books[2]-100;
    }
    best=min(current,best);
    if(books[0]+books[1]>=500){
        current=books[0]+books[1]-100;
        current+=books[2];
        if(books[2]>=500){
            current-=100;
        }
        best=min(current,best);
    }
    if(books[0]+books[2]>=500){
        current=books[0]+books[2]-100;
        current+=books[1];
        if(books[1]>=500){
            current-=100;
        }
        best=min(current,best);
    }
    if(books[1]+books[2]>=500){
        current=books[1]+books[2]-100;
        current+=books[0];
        if(books[0]>=500){
            current-=100;
        }
        best=min(current,best);
    }
    cout<<best<<ENDL;
    return 0;
}