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

string getSum(string current, lli x){
    lli a = stoll(current);
    x+=a;
    string ans = "";
    current = to_string(x);
    int pos = current.size()-1;
    int steps=4;
    while(steps--){
        if(pos<0)break;
        ans+=current[pos--];
    }
    while(ans.size()<4){
        ans+='0';
    }
    reverse(ans.begin(),ans.end());
    return ans;

}

lli getAns(string l, string u, vector<lli> &values){
    queue<string> nex;
    map<string,int> visited;
    visited[l]++;
    nex.push(l);
    lli lvl=0;
    while(nex.size()){
        lli c=nex.size();
        while(c--){
            string current = nex.front();
            nex.pop();
            if(current==u){
                return lvl;
            }
            for(auto x:values){
                string sum = getSum(current,x);
                if(visited.count(sum)==0){
                    nex.push(sum);
                    visited[sum]++;
                }
            }
        }
        lvl++;
    }
    return -1;
}


int main() {_ 
    string l,u;
    int r;
    int c=1;

    while(cin>>l>>u>>r){
        if(r==0){
            break;
        }
        vector<lli> values(r);
        fore(i,0,r){
            cin>>values[i];
        }


        lli ans=getAns(l,u,values);
        if(ans!=-1){
            cout<<"Case "<<c++<<": "<<ans<<ENDL;

        }else{
            cout<<"Case "<<c++<<": Permanently Locked"<<ENDL;
        }

    }
    return 0;
}