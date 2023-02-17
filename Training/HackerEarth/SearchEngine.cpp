#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;


struct Node{
    unordered_map<char,int> letters;
    int weight;

    Node(){
        weight=-1;
    }

};

vector<Node> nodes;
int insert(int p, string &s, int ps, int w ){
    if(ps==s.size()){
        nodes[p].weight= w>nodes[p].weight?w:nodes[p].weight;
        return nodes[p].weight;
    }
    if(nodes[p].letters.count(s[ps])==0){
        nodes[p].letters[s[ps]]=nodes.size();
        nodes.push_back(Node());
    }
    nodes[p].weight=max(nodes[p].weight,insert(nodes[p].letters[s[ps]],s,ps+1,w)) ;
    return nodes[p].weight;
}

int query(int p, string &s, int ps){
    if(ps==s.size()){
        return nodes[p].weight;
    }

    if(nodes[p].letters.count(s[ps])==0){
        return -1;
    }

    return query(nodes[p].letters[s[ps]],s,ps+1);

    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    nodes.push_back(Node());
    int n,q,w;
    string s;
    cin>>n>>q;
    for(int i=0;i<n;++i){
        cin>>s>>w;
        insert(0,s,0,w);
    }

    while(q--){
        cin>>s;
        cout<<query(0,s,0)<<ENDL;
    }

    return 0;
}