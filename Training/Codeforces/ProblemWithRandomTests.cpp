#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
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

int main()
{
    IO;
    int n;
    cin>>n;
    string s;
    cin>>s;
    int start=-1;
    FOR(i,0,n){
        if(s[i]=='1'){
            start=i;
            break;
        }
    }
    if(start==-1){
        start=n-1;
    }
    int totalsize=n-start;
    int firstz=-1;
    FOR(i,start,n){
        if(s[i]=='0'){
            firstz=i;
            break;
        }
    }
    string finalanswer="";
    string current="";
    int actual=0;
    string testing="";
    string aux="";
    if(firstz!=-1){
        int diff=(firstz-start);
        
        while(actual<=diff){
            testing="";
            aux=s.substr(start+actual,totalsize-diff);
            int evaluation=firstz;
            for(auto x:aux){
                if(x=='1'&&s[evaluation]=='0'){
                    testing+='1';
                }else{
                    testing+='0';
                }
                evaluation++;
            }
            if(testing>current){
                current=testing;
            }
            actual++;
        }
    }else{
        firstz=n;
    }

    FOR(i,start,firstz){
        finalanswer+=s[i];
    }
    
    int evaluation=firstz;
    for(auto x:current){
        if(x=='1'){
            finalanswer+='1';
        }else{
            finalanswer+=s[evaluation];
        }
        evaluation++;
    }

    cout<<finalanswer<<ENDL;
    return 0;
}