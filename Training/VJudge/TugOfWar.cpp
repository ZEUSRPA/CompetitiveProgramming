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


pair<int,int> answer;
void doit(vector<int> &aux,int p,vector<int> &a,vector<int> &b){
    if(p==aux.size()){
        int aaa=a.size()-b.size();
        if(abs(aaa)>1){
            return;
        }
        int ca=0,cb=0;
        for(auto x:a){
            ca+=x;
        }
        for(auto x:b){
            cb+=x;
        }
        if(answer.first==-1||abs(answer.first-answer.second)>abs(ca-cb)){
            answer={ca,cb};
        }
        return;
    }
    a.pb(aux[p]);
    doit(aux,p+1,a,b);
    a.pop_back();
    b.pb(aux[p]);
    doit(aux,p+1,a,b);
    b.pop_back();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> aux(n);
        FOR(i,0,n){
            cin>>aux[i];
        }
        answer = {-1,-1};
        vector<int> a;
        vector<int> b;
        doit(aux,0,a,b);
        if(answer.first>answer.second){
            answer={answer.second,answer.first};
        }
        cout<<answer.first<<" "<<answer.second<<ENDL<<ENDL;
    }
    return 0;
}