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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(cin>>s){
        int points=0;
        unordered_map<char,int> suits;
        unordered_map<char,bool> stopped;
        int aces=0;
        unordered_map<char,unordered_map<char,int>> cards;
        cards[s[0]][s[1]]++;
        suits[s[1]]++;
        if(s[0]=='A'){
            aces++;
            stopped[s[1]]=true;
            points+=4;
        }else if(s[0]=='K'){
            points+=3;
        }else if(s[0]=='Q'){
            points+=2;
        }else if(s[0]=='J'){
            points+=1;
        }
        FOR(i,0,12){
            cin>>s;
            cards[s[0]][s[1]]++;
            suits[s[1]]++;
            if(s[0]=='A'){
                aces++;
                stopped[s[1]]=true;
                points+=4;
            }else if(s[0]=='K'){
                points+=3;
            }else if(s[0]=='Q'){
                points+=2;
            }else if(s[0]=='J'){
                points+=1;
            }
        }
        if(cards.count('K')){
            for(auto &x:cards['K']){
                if(suits[x.F]==1){
                    points--;
                }else{
                    stopped[x.first]=true;
                }
            }
        }
        if(cards.count('Q')){
            for(auto &x:cards['Q']){
                if(suits[x.F]<3){
                    points--;
                }else{
                    stopped[x.first]=true;
                }
            }
        }
        if(cards.count('J')){
            for(auto &x:cards['J']){
                if(suits[x.F]<4){
                    points--;
                }
            }
        }
        if(points>=16){
            if(stopped.size()==4){
                cout<<"BID NO-TRUMP"<<ENDL;
                continue;
            }
        }
        for(auto &x:suits){
            if(x.second==2){
                points++;
            }else if(x.S==1){
                points+=2;
            }
        }
        char bid;
        int a=0;
        points+=(4-suits.size())*2;
        if(points<14){
            cout<<"PASS"<<ENDL;
        }else{
            if(suits['S']>a){
                bid='S';
                a=suits['S'];
            }
            if(suits['H']>a){
                bid='H';
                a=suits['H'];
            }
            if(suits['D']>a){
                bid='D';
                a=suits['D'];
            }
            if(suits['C']>a){
                bid='C';
                a=suits['C'];
            }
            cout<<"BID "<<bid<<ENDL;
        }

    }
    return 0;
}