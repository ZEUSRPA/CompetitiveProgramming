#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;


map<char,set<string>> keys;
stack<string> aux;
string password;

bool goodPassword(int l,int r){
    if(l==r){
        return true;
    }
    if(keys.count(password[l])){
        bool si=false;
        for(auto x:keys[password[l]]){
            if(password.find(x,l)==l){
                si=goodPassword(l+x.size(),r);
            }
            if(si){
                aux.push(x);
                return true;
            }
        }
    }
    return false;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n;
    string a;
    
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a;
            keys[a[0]].insert(a);
        }
        cin>>password;
        if(goodPassword(0,password.size())){
            while(true){
                cout<<aux.top();
                aux.pop();
                if(aux.empty()){
                    cout<<ENDL;
                    break;
                }else
                {
                    cout<<" ";
                }
                
            }
        }else{
            cout<<"WRONG PASSWORD"<<ENDL;
        }

    }
    return 0;
}
