#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define lli long long
#define ld long double
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;
vector<int> primes;
vector<bool> criba;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    string n;
    while(t--){
        cin>>n;
        int aux=0;
        for(auto x:n){
            aux+=x-'0';
        }
        vector<bool> childs(7,false);
        int d=n.back()-'0';
        if(d%2==0){
            childs[2]=true;
        }
        if(aux%3==0){
            childs[3]=true;
        }
        string four="";
        if(n.size()>1){
            four=n[n.size()-2];
            four+=n[n.size()-1];
        }else{
            four=n;
        }
        //cout<<four<<ENDL;
        int f=stoi(four);
        if(f%4==0){
            childs[4]=true;
        }
        if(n.back()=='5'||n.back()=='0'){
            childs[5]=true;
        }
        if(childs[2]&&childs[3]){
            childs[6]=true;
        }
        vector<int> ans;
        for(int i=2;i<7;++i){
            if(childs[i]){
                ans.push_back(i);
            }
        }
        if(ans.size()>0){
            for(int i=0;i<ans.size()-1;i++){
                cout<<ans[i]<<" ";
            }
            cout<<ans.back()<<ENDL;

        }else{
            cout<<-1<<ENDL;
        }
        
    }
    return 0;
}

