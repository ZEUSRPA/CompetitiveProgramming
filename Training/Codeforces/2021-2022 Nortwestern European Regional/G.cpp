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



bool isPossible(vector<string> &words, int tam, int siz){
    int last=0;
    int current = 0;
    int cont=0;
    fore(i,0,sz(words)){
        current = max(current,sz(words[i]));
        cont++;
        if(cont==tam){
            cont=0;
            last+=current+1;
            current=0;
        }
    }
    last--;
    deb(tam);
    deb(last);
    if(last<=siz){
        return true;
    }
    return false;
}

vector<int> columns;
vector<string> grid;


void construct(vector<string> &words, int best, int w){
    grid=vector<string>(best,string(w,' '));
    int column=0;
    int last=0;
    int cont=0;
    columns.clear();
    int maxi=0;
    fore(i,0,sz(words)){
        fore(j,0,sz(words[i])){
            grid[cont][last+j]=words[i][j];
        }
        maxi=max(maxi,sz(words[i]));
        cont++;
        if(cont==best){
            cont=0;
            column++;
            columns.pb(maxi);
            last += maxi+1;
            maxi=0;
        }
    }
    if(maxi!=0){
        columns.pb(maxi);
    }
}

int main() {_ 
    int n,w;
    cin>>n>>w;
    string s;
    vector<string> words(n);
    fore(i,0,n){
        cin>>words[i];
    }
    int l=1, r=n;
    int best = 0;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(isPossible(words,mid,w)){
            r=mid-1;
            best = mid;
        }else{
            l=mid+1;
        }
    }
    construct(words,best,w);
    cout<<best<<" "<<sz(columns)<<ENDL;
    for(auto x:columns){
        cout<<x<<" ";
    }
    cout<<ENDL;
    for(auto x:grid){
        cout<<x<<ENDL;
    }
    return 0;
}