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

string transformation(long long int k){
    string res="";
    if(k==1){
        res+='2';
        return res;
    }
    if(k==2){
        res="(2)^2";
        return res;
    }
    if(k%2==0){
        res="("+transformation(k/2)+")^2";
    }else{
        res="(2*"+transformation(k-1)+")";
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int t,k;
    cin>>t;
    while(t--){
        cin>>k;
        cout<<transformation(k)<<ENDL;

    }
    return 0;
}

