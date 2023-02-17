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


int palindrome(string s){
    FOR(i,0,s.size()){
        if(!isalpha(s[i])){
            s.erase(s.begin()+i);
            i--;
        }
    }
    int aux=(int)sqrt(s.size());
    if(aux*aux == s.size()){
        string z=s;
        reverse(z.begin(),z.end());
        if(z!=s){
            return -1;
        }
        FOR(i,0,aux){
            FOR(j,0,aux){
                if(s[i+(aux)*j]!=s[(s.size()-1)-i-(aux)*j]){
                    return -1;
                }
            }
        }
    }else{
        return -1;
    }

    return aux;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    string s;
    cin>>t;
    cin.ignore();
    FOR(i,1,t+1){
        getline(cin,s);
        int ans=palindrome(s);
        cout<<"Case #"<<i<<":"<<ENDL;
        if(ans!=-1){
            cout<<ans<<ENDL;
        }else{
            cout<<"No magic :("<<ENDL;
        }
    }
    return 0;
}