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
    lli n;
    cin>>n;
    string s;
    cin>>s;
    map<int,int> boss;
    lli currentParent = 0;
    string currentstring = "";
    stack<int> st;
    st.push(0);
    fore(i,0,s.size()){
        if(s[i]=='('){
            if(currentstring.size()){
                currentParent=stoll(currentstring);
            }
            st.push(currentParent);
            // deb(st.top());
            currentstring="";
        }else if(s[i]==')'){
            lli current;
            // deb(currentstring);
            if(currentstring.size()){
                current=stoll(currentstring);
                currentstring="";
            }else{
                current=currentParent;
            }
            // deb(current);
            boss[current] = st.top();
            // deb(st.top());
            currentParent=st.top();
            st.pop();
        }else{
            currentstring+=s[i];
        }
    }
    if(st.size()){
        boss[currentParent] = st.top();
    }
    fore(i,1,n){
        cout<<boss[i]<<" ";
    }
    cout<<boss[n]<<ENDL;
    return 0;
}