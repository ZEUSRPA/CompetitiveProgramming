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
    int n;
    cin>>n;
    string s;
    map<string,int> words;
    fore(i,0,n){
        cin>>s;
        string aux=nextP(s);
        string mini=s;
        while(aux!=s){
            if(aux<mini){
                mini=aux;
            }
            aux=nextP(aux);
        }
        words[mini]++;
    }
    cout<<words.size()<<ENDL;
    return 0;
}