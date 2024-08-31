#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    stack<char> pila;
    for(int i=0;i<s.size();++i){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            pila.push(s[i]);
        }else if(s[i]==')'){
            if(pila.top()=='('){
                pila.pop();
            }else{
                cout<<"false"<<'\n';
                return 0;
            }
        }else if(s[i]==']'){
            if(pila.top()=='['){
                pila.pop();
            }else{
                cout<<"false"<<'\n';
                return 0;
            }
        }else if(s[i]=='}'){
            if(pila.top()=='{'){
                pila.pop();
            }else{
                cout<<"false"<<'\n';
                return 0;
            }
        }
    }
    if(pila.size()==0){
        cout<<"true"<<'\n';
    }else{
        cout<<"false"<<'\n';
    }
    return 0;
}