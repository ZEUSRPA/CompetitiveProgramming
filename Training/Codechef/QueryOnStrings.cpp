#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

struct Node{
    vector<int> letters;
    int cont;
    Node(){
        cont=0;
        letters=vector<int>(26,-1);
    }
};
vector<Node> trie;
void add(string &s,int pos,int node){
    trie[node].cont++;
    if(pos==-1){
        return;
    }
    if(trie[node].letters[s[pos]-'a']==-1){
        trie[node].letters[s[pos]-'a']=trie.size();
        trie.push_back(Node());
    }
    add(s,pos-1,trie[node].letters[s[pos]-'a']);
}

bool query(int k,int l,int node){
    if(l==0){
        return k<=trie[node].cont;
    }
    if(trie[node].cont<k){
        return false;
    }
    bool aux=false;
    for(auto &x:trie[node].letters){
        if(!aux){
            if(x>=0){
                aux=query(k,l-1,x);
            }
        }else{
            break;
        }                 
    }
    return aux;
}

void del(string &s,int pos,int node){
    trie[node].cont--;
    if(pos==-1){
        return;
    }
    del(s,pos-1,trie[node].letters[s[pos]-'a']);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    int c,k,l;
    string s;
    trie.push_back(Node());
    map<int,string> words;
    for(int i=1;i<=q;i++){
        cin>>c;
        if(c==1){
            cin>>s;
            words[i]=s;
            add(s,s.size()-1,0);
        }else if(c==2){
            cin>>k>>l;
            cout<<(query(k,l,0)?"YES":"NO")<<ENDL;
        }else{
            cin>>k;
            if(words.count(k)){
                del(words[k],words[k].size()-1,0);
                words.erase(k);
            }
        }
    }
    return 0;
}