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


int main() {_ 
    string s;
    cin>>s;
    string ans="";
    string aux="";
    bool one=false;
    bool two=false;
    fore(i,0,s.size()){
        if(two){
            aux+=s[i];
        }else if(one){
            if(aux.size()>0&&s[i]=='r'&&s[i+1]=='u'){
                two=true;
                aux+='.';
                aux+="ru";
                ans+=aux;
                aux="";
                i++;
            }else{
                aux+=s[i];
            }
        }else{
            aux+=s[i];
            if(aux=="http"||aux=="ftp"){
                one=true;
                ans+=aux;
                ans+="://";
                aux="";
            }
        }
    }
    if(aux.size()){
        ans+="/";
        ans+=aux;
    }
    cout<<ans<<ENDL;
    return 0;
}