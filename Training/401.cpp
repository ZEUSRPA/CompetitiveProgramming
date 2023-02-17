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

unordered_map<char,char> letters;


bool palindrome(string s){
    string aux=s;
    reverse(s.begin(),s.end());
    if(aux==s){
        return true;
    }else{
        return false;
    }
}

bool mirrored(string s){
    int i=0;
    int j=s.size()-1;
    while(i<=j){
        if(letters.count(s[i])){
            if(s[j]!=letters[s[i]]){
                return false;
            }
        }else{
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    letters['A']='A';
    letters['E']='3';
    letters['3']='E';
    letters['H']='H';
    letters['I']='I';
    letters['J']='L';
    letters['L']='J';
    letters['A']='A';
    letters['M']='M';
    letters['O']='O';
    letters['S']='2';
    letters['T']='T';
    letters['U']='U';
    letters['V']='V';
    letters['W']='W';
    letters['X']='X';
    letters['Y']='Y';
    letters['Z']='5';
    letters['1']='1';
    letters['2']='S';
    letters['5']='Z';
    letters['8']='8';

    string s;
    bool next=false;
    while(cin>>s){
        
        bool pal;
        bool mir;
        mir=mirrored(s);
        pal=palindrome(s);
        if(pal && mir){
            cout<<s<<" -- is a mirrored palindrome."<<ENDL;
        }else if(pal && !mir){
            cout<<s<<" -- is a regular palindrome."<<ENDL;
        }else if(!pal && mir){
            cout<<s<<" -- is a mirrored string."<<ENDL;
        }else{
            cout<<s<<" -- is not a palindrome."<<ENDL;
        }
        cout<<ENDL;
    }
    
    return 0;
}