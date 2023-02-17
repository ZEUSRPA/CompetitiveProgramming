#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;


struct Node{
    map<char,int> letters;
    bool end;
    Node(){
        end=false;
    }
};
vector<Node> trie;

bool add(string &s,int pos,int node){
    if(trie[node].end){
        return false;
    }
    if(s.size()==pos){
        trie[node].end=true;
        if(trie[node].letters.size()==0){
            return true;
        }else
        {
            return false;
        }
    }
    if(trie[node].letters.count(s[pos])==0){
        trie[node].letters[s[pos]]=trie.size();
        trie.push_back(Node());
    }
    return add(s,pos+1,trie[node].letters[s[pos]]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n;
    cin>>n;
    string s;
    trie.push_back(Node());
    bool t=true;
    while(n--){
        cin>>s;
        if(t){
            t=add(s,0,0);
            if(!t){
                cout<<"BAD SET"<<ENDL;
                cout<<s<<ENDL;
            }
        }
    }
    if(t){
        cout<<"GOOD SET"<<ENDL;
    }
    return 0;
}