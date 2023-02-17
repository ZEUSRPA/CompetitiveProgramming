#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

struct Node{
    vector<int> letters;
    bool end;
    int cont;
    Node(){
        letters=vector<int>(26,-1);
        end=false;
        cont=0;
    }
};

vector<Node> trie;

void add(string s,int pos,int node){
    trie[node].cont++;
    if(pos==s.size()){
        trie[node].end=true;
        return;
    }
    if(trie[node].letters[s[pos]-'a']==-1){
        trie[node].letters[s[pos]-'a']=trie.size();
        trie.push_back(Node());
    }
    add(s,pos+1,trie[node].letters[s[pos]-'a']);
}

int query(string s, int pos, int node){
    if(pos==s.size()){
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
    lli n;
    cin>>n;
    string a,b;
    trie.push_back(Node());
    while(n--){
        cin>>a>>b;
        if(a=="add"){
            add(b,0,0);
        }else{
            cout<<query(b,0,0)<<ENDL;
        }
    }
    return 0;
}