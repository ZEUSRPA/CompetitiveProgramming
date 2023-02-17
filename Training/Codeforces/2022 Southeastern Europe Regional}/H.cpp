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
    stack<int> one;
    stack<int> two;
    stack<int> three;
    int aux;
    FOR(i,0,n){
        cin>>aux;
        one.push(aux);
    }
    vector<pair<int,int>> moves; 
    bool sorted=false;
    while(!sorted){
        while(one.size()){
            int current=one.top();
            if(two.empty() || current<two.top()){
                moves.pb({1,2});
                one.pop();
                two.push(current);
            }else if(three.empty() || current<three.top()){
                moves.pb({1,3});
                one.pop();
                three.push(current);
            }else{
                break;
            }
        }
        if(one.empty()){
            sorted=true;
        }
        while(two.size()||three.size()){
            if(two.size()&&three.size()){
                if(two.top()<three.top()){
                    moves.pb({2,1});
                    one.push(two.top());
                    two.pop();
                }else{
                    moves.pb({3,1});
                    one.push(three.top());
                    three.pop();
                }
            }else if(two.size()){
                moves.pb({2,1});
                one.push(two.top());
                two.pop();
            }else{
                moves.pb({3,1});
                one.push(three.top());
                three.pop();
            }
        }
    }
    
    while(one.size()){
        moves.pb({1,3});
        three.push(one.top());
        one.pop();
    }
    cout<<moves.size()<<ENDL;
    for(auto x:moves){
        cout<<x.first<<" "<<x.second<<ENDL;
    }
    return 0;
}