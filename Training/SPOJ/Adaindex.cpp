#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

struct Nodo{
    vector<lli> letters;
    lli cont;
    Nodo(){
        letters=vector<lli>(26,-1);
        cont=0;
    }
};
vector<Nodo> trie;
void add(string &s,lli pos, lli node){
    trie[node].cont++;
    if(s.size()==pos){
        return;
    }
    if(trie[node].letters[s[pos]-'a']==-1){
        trie[node].letters[s[pos]-'a']=trie.size();
        trie.push_back(Nodo());
    }
    add(s,pos+1,trie[node].letters[s[pos]-'a']);
}

lli query(string &s,lli pos,lli node){
    if(s.size()==pos){
        return trie[node].cont;
    }
    if(trie[node].letters[s[pos]-'a']!=-1){
        return query(s,pos+1,trie[node].letters[s[pos]-'a']);
    }else{
        return 0;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n,q;
    cin>>n>>q;
    string s;
    trie.push_back(Nodo());
    while(n--){
        cin>>s;
        add(s,0,0);
    }
    while(q--){
        cin>>s;
        cout<<query(s,0,0)<<ENDL;
    }
    return 0;
}