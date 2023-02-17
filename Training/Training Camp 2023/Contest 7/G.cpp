// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define F first
#define S second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define ALL(s) begin(s), end(s)
#define ALLR(s) rbegin(s), rend(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

struct Node{
    vector<int> letter;
    bool end;

    Node(){
        letter=vector<int> (10,-1);
        end =false;
    }
};

vector<Node> trie;

void insert(int node,string &s, int pos){
    if(pos==s.size()){
        trie[node].end=true;
        return;
    }
    if(trie[node].letter[s[pos]-'0']==-1){
        trie[node].letter[s[pos]-'0']=trie.size();
        trie.pb(Node());
    }
    insert(trie[node].letter[s[pos]-'0'],s,pos+1);
}

void getMin(int node, string &s, int pos ,string &ans){
    if(pos==s.size()){
        // return ans;
        return;
    }
    char best = '9';
    int bpos=-1;
    fore(i,0,10){
        if(trie[node].letter[i]!=-1){
            char aux = ((s[pos]-'0'+i)%10)+'0';
            // deb(aux);
            if(aux<=best){
                best=aux;
                bpos=i;
            }
        }
    }
    // deb(best-'0');
    // deb(ans);
    if(bpos!=-1){
        ans+=best;
        getMin(trie[node].letter[bpos],s,pos+1,ans);
        // return ans;
    }
    // return ans;

}

void getMax(int node, string &s, int pos, string & ans){
    if(pos==s.size()){
        // return ans;
        return ;
    }
    char best = '0';
    int bpos = -1;
    fore(i,0,10){
        if(trie[node].letter[i]!=-1){
            char aux = ((s[pos]-'0'+i)%10)+'0';
            // deb(aux);
            if(aux>=best){
                best=aux;
                bpos=i;
            }
        }
    }
    if(bpos!=-1){
        ans+=best;
        getMax(trie[node].letter[bpos],s,pos+1,ans);
        // return ans;
    }
    // return ans;
}

int main() {_ 
    int n;
    cin>>n;
    // vector<string> nums(n);
    string s;
    trie.pb(Node());
    string mini="9999999999999999999";
    string maxi="0000000000000000000";
    cin>>s;
    string aux = "0000000000000000000";
    for(int j=s.size()-1;j>=0;j--){
        aux[19-s.size()+j]=s[j];
    }
    insert(0,aux,0);
    fore(i,1,n){
        cin>>s;
        aux = "0000000000000000000";
        for(int j=s.size()-1;j>=0;j--){
            aux[19-s.size()+j]=s[j];
        }
        // deb(aux);
        // nums[i]=aux;
        string ans = "";
        getMin(0,aux,0,ans);
        // deb(ans);
        mini=min(mini,ans);
        string ans2="";
        getMax(0,aux,0,ans2);
        maxi=max(maxi,ans2);
        // deb(ans2);
        insert(0,aux,0);
    }
    // deb(trie.size());

    string ansmin="", ansmax="";
    int start = 0;
    while(mini[start]=='0'){
        start++;
    }
    fore(i,start,mini.size()){
        ansmin+=mini[i];
    }
    start =0;
    while(maxi[start]=='0'){
        start++;
    }
    fore(i,start,maxi.size()){
        ansmax+=maxi[i];
    }
    if(ansmin==""){
        ansmin="0";
    }
    if(ansmax==""){
        ansmax="0";
    }
    cout<<ansmin<<" "<<ansmax<<ENDL;
    return 0;
}