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

// void substract(string &n){
//     int pos=n.size()-2;
//     n[pos+1]='0';
//     while(true){
//         if(pos>=0){
//             if(n[pos]!='0'){
//                 n[pos]--;
//                 FOR(i,pos+1,n.size()){
//                     n[i]='9';
//                 }
//             }else{
//                 pos--;
//             }
//             break;
//         }else{
//             break;
//         }
//     }
// }

void process(string &s, int &k){
    int cont=0;
    int aux=1;
    string num;
    string res;
    for(auto x:s){
        
        if(isdigit(x)){
            num.push_back(x);
        }else{
            // if(num.size()){
            //     aux=num[num.size()-1]-'0';
            //     while(aux){
            //         cont+=aux;
            //         FOR(i,0,aux){
            //             res.push_back(x);
            //         }
            //         substract(num);
            //         aux=num[num.size()-1]-'0';
                    
            //     }
            // }else{
            //     FOR(i,0,aux){
            //         res.push_back(x);
            //     }
            //     cont+=aux;
            // }
            // aux=1;
            // num.clear();
            if(num.size()){
                try{
                    aux=stoi(num);
                    

                }catch(...){
                    cout<<"unfeasible"<<ENDL;
                    return;
                }
                
            }
            FOR(i,0,aux){
                res.push_back(x);
            }
            cont+=aux;
            aux=1;
            num.clear();
            
        }
        if(cont>k){
            cout<<"unfeasible"<<ENDL;
            return;
        }
    }
    cout<<res<<ENDL;   
}

int main()
{
    IO;
    int t,k;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        cin>>k;
        process(s,k);
    }

    return 0;
}