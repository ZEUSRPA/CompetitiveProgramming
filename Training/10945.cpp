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


bool palindrome(string s){
    int i=0;
    int j=s.size()-1;
    while(i<=j){
        if(!isalpha(s[i])){
            i++;
            continue;
        }
        if(!isalpha(s[j])){
            j--;
            continue;
        }
        s[i]=tolower(s[i]);
        s[j]=tolower(s[j]);
        if(s[i]!=s[j]){
            return false;
        }
        i++;;
        j--;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(getline(cin,s)){
        if(s=="DONE"){
            break;
        }

        if(palindrome(s)){
            cout<<"You won't be eaten!"<<ENDL;
        }else{
            cout<<"Uh oh.."<<ENDL;
        }
    }
    return 0;
}