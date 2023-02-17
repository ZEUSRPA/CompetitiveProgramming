#include <bits/stdc++.h>
#define ENDL '\n'
#define FOR(i,a,n) for(int i=(a);i<(n);i++)
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s,aux;
    unordered_map<string,int> words;
    getline(cin,s);
    aux="";
    for(auto &x:s){
        if(x==' '){
            words[aux]++;
            aux.clear();
        }else{
            aux+=x;
        }
    }
    words[aux]++;
    double a=0,b=0,ac=101,w;
    FOR(i,0,2){
        getline(cin,s);
        aux="";
        for(auto &x:s){
            if(x==' '){
                if(words[aux]){
                    a++;
                }
                b++;
                aux.clear();
            }else{
                aux+=x;
            }
        }
        if(words[aux]){
            a++;
        }
        b++;
        if(a/b<ac){
            ac=a/b;
            w=i;
        }
    }
    if(w==0){
        cout<<"NUMBER ONE IS THE HUMAN"<<ENDL;
    }else{
        cout<<"NUMBER TWO IS THE HUMAN"<<ENDL;
    }
    return 0;
}