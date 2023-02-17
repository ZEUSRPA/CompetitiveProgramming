// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define F first
#define S second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
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
    lli n,k,m,c,d;
    cin>>n>>k>>m>>c>>d;
    vector<lli> sequence(n);
    unordered_map<lli,lli> pos;
    vector<lli> prefix(n,0);
    cin>>sequence[0];
    prefix[0]=sequence[0];

    lli bestsum=0;
    lli bestpos=m-1;
    lli mini=INT_MAX;
    bool found=false;
    fore(i,1,n){
        cin>>sequence[i];
        pos[sequence[i]]=i;
        
    }
    auto aux = sequence;
    sort(aux.rbegin(),aux.rend());
    lli kth = aux[k-1];
    bool its=false;
    fore(i,0,m){
        if(i>0){
            prefix[i]=prefix[i-1]+sequence[i];
        }
        if(sequence[i]==kth){
            its=true;
        }
    }
    if(its){
        // bestsum=prefix[m-1]-prefix[m-1-m];
        bestpos=m-1;
    }
    fore(i,m,n){
        prefix[i]=prefix[i-1]+sequence[i];
        if(!found){
            if(i>=m-1){
                lli current=prefix[i]-prefix[i-m];
                if(sequence[i]==kth){
                    if(current>=bestsum){
                        bestsum=current;
                        bestpos=i;
                    }
                }
            }
        }
    }

    vector<lli> adition(m,c);
    fore(i,1,m){
        adition[i]=adition[i-1]+d;
    }
    lli position = m-1;
    while(m--){
        sequence[bestpos--]+=adition[position--];
    }
    sort(sequence.rbegin(),sequence.rend());
    cout<<sequence[k-1]<<ENDL;

    return 0;
}