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


lli getRectangles(lli n, lli m){
    lli ans=0;
    fore(i,0,n){
        fore(j,0,m){
            ans+=(n-i)*(m-j);
        }
    }
    return ans;
}

vector<string> getAns(lli n, lli m,lli need){
    vector<string> res;
    string ans = "";
    if(n==1){
        bool si=false;
        lli curr=0;
        pair<int,int> sol;
        fore(i,0,m){
            deb(i);
            lli aux = ((i)*(i+1))/2;
            aux+=((m-i-1)*(m-i))/2;
            deb(aux);
            aux++;
            if(aux==need){
                si=true;
                sol={i,i};
                break;
            }
        }
        if(!si){
            fore(i,0,m-1){
                lli aux = ((i)*(i+1))/2;
                aux+=((m-i-2)*(m-i-1))/2;
                aux+=3;
                deb(aux);
                if(aux==need){
                    si=true;
                    sol={i,i+1};
                    break;
                }
            }
        }
        fore(i,0,m){
            if(sol.first==i||sol.second==i){
                ans+="1";
            }else{
                ans+="0";
            }
        }
        res.pb(ans);
    }else if(m==1){
        unordered_map<int,int> aux;
        pair<int,int> sol;
        lli curr=n;
        
        fore(i,0,n){
            if(aux.count(need-curr)){
                sol={i,aux[need-curr]};
                break;
            }
            aux[curr]=i;
            curr--;
        }
        deb(sol.first);
        deb(sol.second);
        if(n%2){
            sol={n/2+1,n/2+1};
        }
        fore(i,0,n){
            if(i==sol.first||i==sol.second){
                res.pb("1");
            }else{
                res.pb("0");
            }
        }
    }else{
        fore(i,0,n){
            bool current=0;
            ans="";
            fore(j,0,m){
                if(j>0){
                    ans+=" ";
                }
                ans+=to_string(current);
                current=!current;
            }
            res.pb(ans);
        }
    }
    return res;
        
}

int main() {_ 
    lli t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        bool swapped=false;
        lli rectangles = getRectangles(n,m);
        deb(rectangles);
        if(rectangles%2==0){
            cout<<"Yes"<<ENDL;
            auto res = getAns(n,m,rectangles/2);
            fore(i,0,n){
                fore(j,0,m){
                    if(j>0){
                        cout<<" ";
                    }
                    cout<<res[i][j];
                    
                }
                cout<<ENDL;
            }
            
        }else{
            cout<<"No"<<ENDL;
        }
    }
    return 0;
}