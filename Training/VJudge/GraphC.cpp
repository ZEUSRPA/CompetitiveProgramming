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

unordered_map<char,unordered_map<char,int>> g;
unordered_map<char,int> visited;
void getAns(char node){
    for(auto x:g[node]){
        if(visited.count(x.first)==0){
            visited[x.first]++;
            getAns(x.first);
        }
    }
}

int main() {_ 
    int t;
    cin>>t;
    string s;
    int c=1;
    cin.ignore();
    getline(cin,s);
    while(t--){
        g.clear();
        visited.clear();
        getline(cin,s);
        char maxi = s[0];
        // deb(s);
        while(getline(cin,s)){
            // deb(s);
            if(s==""){
                break;
            }
            g[s[0]][s[1]]++;
            g[s[1]][s[0]]++;
        }
        int ans=0;
        fore(i,'A',maxi+1){
            if(visited.count(i)==0){
                visited[i]++;
                ans++;
                getAns(i);

            }
        }
        if(c>1){
            cout<<ENDL;
        }
        cout<<ans<<ENDL;
        c++;
    }
    return 0;
}