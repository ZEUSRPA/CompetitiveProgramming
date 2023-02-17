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
    lli t,n;
    cin>>t;
    string s;
    while(t--){
        cin>>n;
        cin>>s;
        vector<lli> answer;
        lli current=0;
        lli l=0,r=n-1;
        for(int i=0;i<n;++i){
            if(s[i]=='L'){
                current+=i;
            }else{
                current+=(n-1-i);
            }
        }
        while(l<r){
            lli one=0;
            lli two=0;
            bool si=false;
            if(s[l]=='L'){
                one=(n-1-l)-l;
                si=true;
            }

            if(s[r]=='R'){
                two=r-(n-1-r);
                si=true;
            }
            if(si){
                if(one==two){
                    current+=one;
                    answer.pb(current);
                    current+=one;
                    answer.pb(current);
                }else if(one>two){
                    current+=one;
                    answer.pb(current);
                    if(two){
                        current+=two;
                        answer.pb(current);
                    }
                }else{
                    current+=two;
                    answer.pb(current);
                    if(one){
                        current+=one;
                        answer.pb(current);
                    }
                }
            }
            l++;
            r--;
        }
        while(answer.size()<n){
            answer.pb(current);
        }
        for(lli x:answer){
            cout<<x<<" ";
        }
        cout<<ENDL;
    }
    return 0;
}