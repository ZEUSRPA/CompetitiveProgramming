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

int main() {_ 
    lli t,k;
    string s;
    cin>>t;
    while(t--){
        cin>>s>>k;
        string answer="";
        string aux="";
        bool bad=false;
        lli left=k;
        fore(i,0,sz(s)){
            if(isdigit(s[i])){
                aux+=s[i];
            }else{
                if(aux.size()>10){
                    bad=true;
                    break;
                }else if(aux.size()==0){
                    lli current=1;
                    if(left>=current){
                        left-=current;
                        fore(j,0,current){
                            answer+=s[i];
                        }
                    }else{
                        bad=true;
                        break;
                    }
                }else{
                    lli current=stoi(aux);
                    if(left>=current){
                        left-=current;
                        fore(j,0,current){
                            answer+=s[i];
                        }
                    }else{
                        bad=true;
                        break;
                    }

                }
                aux="";
            }
        }
        if(bad){
            cout<<"unfeasible"<<ENDL;
        }else{
            cout<<answer<<ENDL;
        }
    }
    return 0;
}