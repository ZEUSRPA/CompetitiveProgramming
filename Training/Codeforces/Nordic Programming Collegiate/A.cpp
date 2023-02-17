// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define f first
#define s second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
#define deb(x) cout << #x": " << (x) << endl;

int main(){ _
    int n;
    cin>>n;
    string s;
    vector<int> scores(2,0);//bob alice
    vector<int> current(2);
    vector<bool> isbob={true,true,true,false,false,true,true,false,false,true,true,false,false,true,true,false,false,true,true,false,false,true,true,false,false};
    int index = -1;
    int currentIndex = 1;
    bool finished = false;
    while(n--){
        cin>>s;
        string aux;
        if(index==-1){
            for(auto x:s){
                if(x=='-'){
                    current[0]=stoi(aux);
                    aux="";
                }else{
                    aux+=x;
                }
            }
            current[1]=stoi(aux);
            int round=current[0]+current[1];
            if(round<22){
                if(!isbob[round]){
                    swap(current[0],current[1]);
                }
                if(finished){
                    if(current[0]!=scores[0] || current[1]!=scores[1]){
                        index = currentIndex;
                    }
                }else if(current[0]>=scores[0] && current[1]>=scores[1]){
                    scores[0]=current[0];
                    scores[1]=current[1];
                    if(current[0]>10||current[1]>10){
                        finished=true;
                    }
                }else{
                    index = currentIndex;
                }

            }else{
                index = currentIndex;
            }

        }
        currentIndex++;
        
    }
    if(index==-1){
        cout<<"ok"<<ENDL;
    }else{
        cout<<"error "<<index<<ENDL;
    }
    return 0;
}